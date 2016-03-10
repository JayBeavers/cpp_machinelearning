#include <mlpack/core.hpp>
#include <iostream>
#include <tuple>
#include "../gnuplot-iostream/gnuplot-iostream.h"

using arma::mat;
using std::tuple;

float computeCost(mat X, mat y, mat theta);

tuple<mat, mat> gradientDescent(mat X, mat y, mat theta, float alpha, int32_t iterations);

void graphGradientDescent(mat trainingData, mat predictionData);
void graphCostHistory(mat jHistory);
