#include "interpolation.h"

namespace numerical {

std::function<double(double)> lagrange_interpolation(
    const std::vector<double>& x, 
    const std::vector<double>& y
) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("x and y vectors must have the same size");
    }
    
    if (x.size() == 0) {
        throw std::invalid_argument("Input vectors cannot be empty");
    }
    
    return [x, y](double x_point) {
        return lagrange_evaluate(x, y, x_point);
    };
}

double lagrange_evaluate(
    const std::vector<double>& x, 
    const std::vector<double>& y, 
    double x_point
) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("x and y vectors must have the same size");
    }
    
    if (x.size() == 0) {
        throw std::invalid_argument("Input vectors cannot be empty");
    }
    
    double result = 0.0;
    
    for (size_t i = 0; i < x.size(); i++) {
        double term = y[i];
        
        for (size_t j = 0; j < x.size(); j++) {
            if (j != i) {
                if (x[i] == x[j]) {
                    throw std::invalid_argument("x values must be distinct");
                }
                term *= (x_point - x[j]) / (x[i] - x[j]);
            }
        }
        
        result += term;
    }
    
    return result;
}

} // namespace numerical
