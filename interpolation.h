#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <string>

namespace numerical {

// Lagrange Interpolation
// Returns a function that represents the Lagrange polynomial
std::function<double(double)> lagrange_interpolation(
    const std::vector<double>& x, 
    const std::vector<double>& y
);

// Evaluate Lagrange polynomial at a specific point
double lagrange_evaluate(
    const std::vector<double>& x, 
    const std::vector<double>& y, 
    double x_point
);

// Newton's Divided Difference Interpolation
// Returns a function that represents the Newton polynomial
std::function<double(double)> newton_divided_difference(
    const std::vector<double>& x, 
    const std::vector<double>& y
);

// Evaluate Newton's divided difference polynomial at a specific point
double newton_divided_difference_evaluate(
    const std::vector<double>& x, 
    const std::vector<double>& y, 
    double x_point
);

// Calculate the divided difference table
std::vector<std::vector<double>> divided_difference_table(
    const std::vector<double>& x, 
    const std::vector<double>& y
);

} // namespace numerical

#endif // INTERPOLATION_H
