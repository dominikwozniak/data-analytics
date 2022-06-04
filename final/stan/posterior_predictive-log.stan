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

transformed parameters {
 vector[n] mu;
 mu = alpha + beta_w * weight_center + beta_cyl * cylinders_center + beta_hp * hp_center;
}

model {
  // vector[n] mu;
  // mu = alpha + beta_w * weight_center + beta_cyl * cylinders_center + beta_hp * hp_center;
  
  mpg ~ normal(mu, sigma);
}

generated quantities {
  real y_rep[n] = normal_rng(alpha + beta_w * weight_center + beta_cyl * 
    cylinders_center + beta_hp * hp_center, sigma);
    
  vector[n] log_lik;
  for (j in 1:n) {
    log_lik[j] = normal_lpdf(mpg[j] | mu[j], sigma);
  }
}
