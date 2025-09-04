#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <functional>
#include <stdexcept>
#include <cmath>
#include <string>

namespace numerical {

struct IntegrationResult {
    double value;
    double error_estimate;
    std::string message;
};

// Trapezoidal Rule for numerical integration
IntegrationResult trapezoidal_rule(
    std::function<double(double)> f, 
    double a, 
    double b, 
    int n = 100
);

// Simpson's 1/3 Rule for numerical integration
IntegrationResult simpsons_rule(
    std::function<double(double)> f, 
    double a, 
    double b, 
    int n = 100
);

} // namespace numerical

#endif // INTEGRATION_H
