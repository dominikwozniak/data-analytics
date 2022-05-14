import pandas as pd
from typing import NewType, Any, Callable, Dict, List, Tuple, Union
from dataclasses import dataclass

StanInputNumber = Union[float, int]
StanInputList = List[Union[StanInputNumber, "StanInputList"]]
StanInputValue = Union[StanInputNumber, StanInputList]
StanInput = NewType("StanInput", Dict[str, StanInputValue])
CoordDict = NewType("CoordDict", Dict[str, List[str]])

@dataclass
class PreparedData:
    name: str
    coords: CoordDict
    dims: Dict[str, Any]
    measurements: pd.DataFrame
    number_of_cv_folds: int
    stan_input_function: Callable[..., StanInput]
