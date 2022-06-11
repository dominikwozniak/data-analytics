data {
  int N;
  vector[N] mpg;
  vector[N] weight_center;
}

parameters {
  real alpha;
  real beta_w;
  real<lower = 0> sigma;
}

transformed parameters {
  vector[N] mu;
  mu = alpha + beta_w * weight_center;
}

model {
  mpg ~ normal(mu, sigma);
}

generated quantities {
  real y_rep[N] = normal_rng(alpha + beta_w * weight_center, sigma);
  vector[N] log_lik;
 
  for (i in 1:N) {
    log_lik[i] = normal_lpdf(mpg[i] | mu[i], sigma);
  }
}
