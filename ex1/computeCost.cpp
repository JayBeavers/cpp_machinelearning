#include "./example1.h"

using arma::mat;

float computeCost(mat X, mat y, mat theta) {
  auto const m = y.n_cols;
  auto const prediction = X.t() * theta.t();
  auto const variance = prediction - y.t();

  float j = accu(pow(variance, 2)) / (2 * m);

  return j;
}
