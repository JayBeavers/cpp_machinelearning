#include "./example1.h"

using arma::mat;
using arma::zeros;

mat gradientDescent(mat X, mat y, mat theta, float alpha, int32_t iterations) {
  auto const m = y.n_cols;
  auto jHistory = zeros(iterations, 1);

  for (auto i = 0; i < iterations; i++) {
    auto const prediction = X.t() * theta.t();
    auto const variance = prediction - y.t();
    auto const delta = (variance.t() * X.t()) / m;
    theta = theta - alpha * delta;
  }

  return theta;
}
