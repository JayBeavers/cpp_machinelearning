#include "./example1.h"

using arma::mat;
using arma::zeros;
using std::tuple;

tuple<mat, mat> gradientDescent(mat X, mat y, mat theta, float alpha, int32_t iterations) {
  auto const m = y.n_cols;
  mat jHistory = zeros(iterations, 2);

  for (auto i = 0; i < iterations; i++) {
    auto const prediction = X.t() * theta.t();
    auto const variance = prediction - y.t();
    auto const delta = (variance.t() * X.t()) / m;
    theta = theta - alpha * delta;

    jHistory(i, 0) = i;
    jHistory(i, 1) = computeCost(X, y, theta);
  }

  return std::make_tuple(theta, jHistory);
}
