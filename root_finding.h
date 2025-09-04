#ifndef ROOT_FINDING_H
#define ROOT_FINDING_H

#include <functional>
#include <stdexcept>
#include <cmath>
#include <string>

namespace numerical {

struct RootFindingResult {
    double root;
    int iterations;
    double error;
    bool converged;
    std::string message;
};

// Bisection Method
RootFindingResult bisection(
    std::function<double(double)> f, 
    double a, 
    double b, 
    double tol = 1e-6, 
    int max_iter = 100
);

// Newton-Raphson Method
RootFindingResult newton_raphson(
    std::function<double(double)> f, 
    std::function<double(double)> df, 
    double x0, 
    double tol = 1e-6, 
    int max_iter = 100
);

// Secant Method
RootFindingResult secant(
    std::function<double(double)> f, 
    double x0, 
    double x1, 
    double tol = 1e-6, 
    int max_iter = 100
);

// Fixed Point Iteration
RootFindingResult fixed_point(
    std::function<double(double)> g, 
    double x0, 
    double tol = 1e-6, 
    int max_iter = 100
);

} // namespace numerical

#endif // ROOT_FINDING_H
