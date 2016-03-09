#include "./example1.h"

using std::cout;
using std::endl;
using arma::mat;
using arma::randu;
using arma::ones;
using arma::zeros;
using mlpack::data::Load;

int main() {
  auto data = mat();
  Load("ex1data1.txt", data);

  auto const x = data.row(0);
  auto const y = data.row(1);
  auto const m = y.n_cols;

  plotData(data);

  auto const X = join_vert(ones(1, m), x);
  auto theta = zeros(1, 2);

  auto const iterations = 1500;
  auto alpha = 0.01;

  return 0;
}
