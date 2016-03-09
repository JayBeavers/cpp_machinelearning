#include "./example1.h"

using std::endl;
using arma::mat;

void plotData(mat data) {
  Gnuplot gp;

  gp << "set title 'Food Truck Profit'\n";
  gp << "set xlabel 'Population of City in 10,000s'\n";
  gp << "set ylabel 'Profit in $10,000s'\n";
  gp << "unset key\n";
  gp << "plot " << gp.binFile1d_colmajor(data, "record");
  gp << "with points pt 2 lc rgb 'red'\n";
  gp << endl;
}
