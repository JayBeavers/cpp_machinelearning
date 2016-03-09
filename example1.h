#include <mlpack/core.hpp>
#include <iostream>
#include "gnuplot-iostream/gnuplot-iostream.h"

using arma::mat;

void plotData(mat data);
float computeCost(mat X, mat y, mat theta);
