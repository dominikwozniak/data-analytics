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
  
  alpha ~ normal(20, 5);
  beta_w ~ normal(-10, 5);
  beta_cyl ~ normal(0, 5);
  beta_hp ~ normal(0, 5);
  sigma ~ uniform(0, 10);
  
  mpg ~ normal(mu, sigma);
}

generated quantities {
  real y_rep[n] = normal_rng(alpha + beta_w * weight_center + beta_cyl * 
  cylinders_center + beta_hp * hp_center, sigma);
}
