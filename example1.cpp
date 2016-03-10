#include "./example1.h"

using std::cout;
using std::endl;
using arma::mat;
using arma::randu;
using arma::ones;
using arma::zeros;
using mlpack::data::Load;

int main() {
  Gnuplot gp;
  gp << "set title 'Food Truck Profit'\n";
  gp << "set xlabel 'Population of City in 10,000s'\n";
  gp << "set ylabel 'Profit in $10,000s'\n";
  gp << "unset key\n";
  gp << "set xrange [3:25];\n";
  gp << "set yrange [-5:30]\n";
  gp << "set multiplot\n";

  auto data = mat();
  Load("ex1data1.txt", data);

  auto const x = data.row(0);
  auto const y = data.row(1);
  auto const m = y.n_cols;

  gp << "plot " << gp.binFile1d_colmajor(data, "record");
  gp << "with points title 'Training Data' pt 2 lc rgb 'red'\n";
  gp << endl;

  auto const X = join_vert(ones(1, m), x);
  auto initialTheta = zeros(1, 2);

  auto iterations = 1500;
  auto alpha = 0.01;

  auto j = computeCost(X, y, initialTheta);

  cout << j << endl;

  auto theta = gradientDescent(X, y, initialTheta, alpha, iterations);

  cout << "Theta determined by gradient descent is " << theta << endl;

  auto predict = theta * X;

  mat graphData = join_vert(x, predict);

  gp << "plot " << gp.binFile1d_colmajor(graphData, "record");
  gp << "with line title 'Linear Regression'\n";
  gp << endl;

  mat data1 = { 1, 3.5 };
  int pred1 = accu(data1 * theta.t()) * 10000;
  mat data2 = { 1, 7.0 };
  int pred2 = accu(data2 * theta.t()) * 10000;

  cout << "For population 35k, we predict a profit of " << pred1 << endl;
  cout << "For population 70k, we predict a profit of " << pred2 << endl;

  return 0;
}
