#include <mlpack/core.hpp>
#include <iostream>
#include "gnuplot-iostream/gnuplot-iostream.h"

using arma::mat;

float computeCost(mat X, mat y, mat theta);

mat gradientDescent(mat X, mat y, mat theta, float alpha, int32_t iterations);
