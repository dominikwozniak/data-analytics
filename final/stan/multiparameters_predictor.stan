data {
  int n;
  vector[n] mpg;
  vector[n] weight_center;
  vector[n] cylinders_center;
  vector[n] hp_center;
}

parameters {
  real alpha;
  real beta_w;
  real beta_cyl;
  real beta_hp;
  real<lower = 0> sigma;
}

model {
  vector[n] mu;
  mu = alpha + beta_w * weight_center + beta_cyl * cylinders_center + beta_hp * hp_center;
  
  mpg ~ normal(mu, sigma);
}