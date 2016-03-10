#include "./example1.h"

using arma::mat;
using std::endl;

void graphGradientDescent(mat trainingData, mat predictionData) {
  Gnuplot gp;

  gp << "set title 'Food Truck Profit'\n";
  gp << "set xlabel 'Population of City in 10,000s'\n";
  gp << "set ylabel 'Profit in $10,000s'\n";
  gp << "unset key\n";
  gp << "set xrange [3:25]\n";
  gp << "set yrange [-5:30]\n";
  gp << "set multiplot\n";

  gp << "plot " << gp.binFile1d_colmajor(trainingData, "record");
  gp << "with points title 'Training Data' pt 2 lc rgb 'red'\n";
  gp << endl;

  gp << "plot " << gp.binFile1d_colmajor(predictionData, "record");
  gp << "with line title 'Linear Regression'\n";
  gp << "unset multiplot\n";
  gp << endl;
}

void graphCostHistory(mat jHistory) {
  Gnuplot gp;

  gp << "set title 'Cost over iterations'\n";
  gp << "set xlabel 'Iterations'\n";
  gp << "set ylabel 'Cost Function'\n";
  gp << "plot " << gp.binFile1d(jHistory, "record");
  gp << "with line title 'J History'\n";
  gp << endl;
}
