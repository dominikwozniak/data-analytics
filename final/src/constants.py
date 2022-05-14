import os

DIMS = {
    "y": ["observation"],
    "batch_size": ["observation"],
    "yrep": ["observation"],
    "llik": ["observation"],
}
N_CV_FOLDS = 10
HARDCODED_NUMBERS = {
    "r": (1.68 / 2) / 12,  # radius of a 1.68 inch wide golf ball in feet
    "R": (4.25 / 2) / 12,  # radius of a 4.25 inch wide golf hole in feet
    "overshot": 1,  # putter's target distance minus x
    "distance_tolerance": 3,  # success only if distance is in [x, x+3]
}

CURRENT_DIR = os.getcwd()
DATA_DIR = os.path.abspath(f"{CURRENT_DIR}/data")
STAN_INPUTS_DIR = os.path.abspath(f"{CURRENT_DIR}/data/stan_inputs")

MEASUREMENTS_FILE = os.path.join(DATA_DIR, "measurements.csv")
INPUT_PRIOR_FILE = os.path.join(DATA_DIR, f"stan_input_prior.json")
INPUT_POSTERIOR_FILE = os.path.join(DATA_DIR, f"stan_input_posterior.json")