#include "./example1.h"

using std::cout;
using std::endl;
using arma::mat;
using arma::randu;
using arma::ones;
using arma::zeros;
using mlpack::data::Load;

int main() {
  auto iterations = 1500;
  auto alpha = 0.01;
  auto initialTheta = zeros(1, 2);

  auto trainingData = mat();
  Load("ex1data1.txt", trainingData);

  auto const x = trainingData.row(0);
  auto const y = trainingData.row(1);
  auto const m = y.n_cols;

  auto const X = join_vert(ones(1, x.n_cols), x);
  auto j = computeCost(X, y, initialTheta);
  cout << j << endl;

  auto rval = gradientDescent(X, y, initialTheta, alpha, iterations);
  auto theta = std::get<0>(rval);
  cout << "Theta determined by gradient descent is " << theta << endl;

  auto predictions = theta * X;
  mat predictionData = join_vert(x, predictions);

  graphGradientDescent(trainingData, predictionData);

  auto jHistory = std::get<1>(rval);
  graphCostHistory(jHistory);

  mat data1 = { 1, 3.5 };
  int pred1 = accu(data1 * theta.t()) * 10000;
  mat data2 = { 1, 7.0 };
  int pred2 = accu(data2 * theta.t()) * 10000;

  cout << "For population 35k, we predict a profit of " << pred1 << endl;
  cout << "For population 70k, we predict a profit of " << pred2 << endl;

  return 0;
}
