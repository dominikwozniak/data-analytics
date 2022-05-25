data {
  int n;
  vector[n] mpg;
  vector[n] weight;
}

parameters {
  real alpha;
  real beta_w;
  real sigma;
}

model {
  vector[n] mu;
  mu = alpha + beta_w * weight;
  
  mpg ~ normal(mu, sigma);
}
