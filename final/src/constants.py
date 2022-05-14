import os

DIMS = {
    "y": ["observation"],
    "batch_size": ["observation"],
    "yrep": ["observation"],
    "llik": ["observation"],
}
R_BALL = (1.68 / 2) / 12  # radius of a 1.68 inch wide golf ball in feet
R_HOLE = (4.25 / 2) / 12  # radius of a 4.25 inch wide golf hole in feet
OVERSHOT = 1, # putter's target distance minus x
TOLERANCE_DISTANCE = 3 # success only if distance is in [x, x+3]

CURRENT_DIR = os.getcwd()
DATA_DIR = os.path.abspath(f"{CURRENT_DIR}/data")
STAN_INPUTS_DIR = os.path.abspath(f"{CURRENT_DIR}/data/stan_inputs")
RESULTS_DIR = os.path.abspath(f"{CURRENT_DIR}/results")
STAN_DIR = os.path.abspath(f"{CURRENT_DIR}/src/stan")
SAMPLE_DIR = os.path.abspath(f"{CURRENT_DIR}/data/sample")

MEASUREMENTS_FILE = os.path.join(DATA_DIR, "measurements.csv")
INPUT_PRIOR_FILE = os.path.join(DATA_DIR, "stan_input_prior.json")
INPUT_POSTERIOR_FILE = os.path.join(DATA_DIR, "stan_input_posterior.json")