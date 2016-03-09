#include "./example1.h"

using std::endl;
using arma::mat;

float computeCost(mat X, mat y, mat theta) {
  auto const m = y.n_cols;
  auto const prediction = X.t() * theta.t();
  auto const delta = prediction - y.t();

  float j = accu(pow(delta, 2)) / (2 * m);

  return j;
}
