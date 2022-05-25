data {
  int n;
  vector[n] mpg;
  vector[n] weight_center;
}

parameters {
  real alpha;
  real beta_w;
  real<lower = 0> sigma;
}

model {
  vector[n] mu;
  mu = alpha + beta_w * weight_center;
  
  mpg ~ normal(mu, sigma);
}
