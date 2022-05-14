import pandas as pd
import numpy as np
from sklearn.model_selection import KFold
from typing import Dict, List, Tuple
from src.types import StanInputNumber, StanInputList, StanInputValue, StanInput, CoordDict, PreparedData
from src.constants import DIMS, HARDCODED_NUMBERS

def get_stan_input(
    measurements: pd.DataFrame,
    likelihood: bool,
    train_ix: List[int],
    test_ix: List[int],
) -> StanInput:
    """Turn a processed dataframe into a Stan input."""
    return stanify_dict(
        {
            "N": len(measurements),
            "N_train": len(train_ix),
            "N_test": len(test_ix),
            "x": measurements["x"],
            "y": measurements["y"],
            "batch_size": measurements["n"],
            "likelihood": int(likelihood),
            "ix_train": [i + 1 for i in train_ix],
            "ix_test": [i + 1 for i in test_ix],
            "r": HARDCODED_NUMBERS["r"],
            "R": HARDCODED_NUMBERS["R"],
            "overshot": HARDCODED_NUMBERS["overshot"],
            "distance_tolerance": HARDCODED_NUMBERS["distance_tolerance"],
        }
    )

def get_stan_inputs(
    prepared_data: PreparedData,
) -> Tuple[StanInput, StanInput, List[StanInput]]:
    """Get Stan input dictionaries for all modes from a PreparedData object."""
    ix_all = list(range(len(prepared_data.measurements)))
    stan_input_prior, stan_input_posterior = (
        prepared_data.stan_input_function(
            measurements=prepared_data.measurements,
            train_ix=ix_all,
            test_ix=ix_all,
            likelihood=likelihood,
        )
        for likelihood in (False, True)
    )
    stan_inputs_cv = []
    kf = KFold(prepared_data.number_of_cv_folds, shuffle=True)
    for train, test in kf.split(prepared_data.measurements):
        stan_inputs_cv.append(
            prepared_data.stan_input_function(
                measurements=prepared_data.measurements,
                likelihood=True,
                train_ix=list(train),
                test_ix=list(test),
            )
        )
    return stan_input_prior, stan_input_posterior, stan_inputs_cv

def process_measurements(measurements_raw: pd.DataFrame, pref) -> pd.DataFrame:
    """Process the measurements.

    Since the data is already as clean as possible, this function just adds a
    prefix to the index.

    """
    return measurements_raw.copy().rename(lambda i: f"{pref}_{i}")

def stanify_dict(d: Dict) -> StanInput:
    """Make sure a dictionary is a valid Stan input.

    :param d: input dictionary, possibly with wrong types
    """
    out = {}
    for k, v in d.items():
        if not isinstance(k, str):
            raise ValueError(f"key {str(k)} is not a string!")
        elif isinstance(v, pd.Series):
            out[k] = v.to_list()
        elif isinstance(v, pd.DataFrame):
            out[k] = v.values.tolist()
        elif isinstance(v, np.ndarray):
            out[k] = v.tolist()
        else:
            out[k] = v
    return StanInput(out)

def prepare_data(measurements_raw: pd.DataFrame) -> PreparedData:
    """Prepare the old data."""
    measurements = process_measurements(measurements_raw, "old")
    return PreparedData(
        name="old", # TODO: remove
        coords=CoordDict({"observation": measurements.index.tolist()}),
        dims=DIMS,
        measurements=measurements,
        number_of_cv_folds=10,
        stan_input_function=get_stan_input,
    )
