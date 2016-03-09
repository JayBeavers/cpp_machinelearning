#include <mlpack/core.hpp>
#include <iostream>
#include "gnuplot-iostream/gnuplot-iostream.h"

using std::cout;
using std::endl;
using arma::mat;
using arma::randu;
using mlpack::data::Load;

int main() {
  Gnuplot gp;

  auto data = mat();
  Load("ex1data1.txt", data);

  auto X = data.row(0);
  auto y = data.row(1);

  auto m = y.n_cols;

  cout << X << endl;
  cout << y << endl;
  cout << m << endl;

  gp << "set title 'Food Truck Profit'\n";
  gp << "set xlabel 'Population of City in 10,000s'\n";
  gp << "set ylabel 'Profit in $10,000s'\n";
  gp << "unset key\n";
  gp << "plot " << gp.binFile1d_colmajor(data, "record");
  gp << "with points pt 2 lc rgb 'red'\n";
  gp << endl;

  return 0;
}
