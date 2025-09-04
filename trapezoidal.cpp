#include "integration.h"

namespace numerical {

IntegrationResult trapezoidal_rule(
    std::function<double(double)> f, 
    double a, 
    double b, 
    int n
) {
    IntegrationResult result;
    
    if (n <= 0) {
        throw std::invalid_argument("Number of intervals must be positive");
    }
    
    if (a > b) {
        // Swap a and b if a > b
        std::swap(a, b);
        result.message = "Warning: Lower bound greater than upper bound. Bounds were swapped.";
    } else {
        result.message = "Success: Trapezoidal rule applied successfully";
    }
    
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    result.value = h * sum;
    
    // Simple error estimate based on halving the number of intervals
    if (n >= 2) {
        double h_half = (b - a) / (n / 2);
        double sum_half = 0.5 * (f(a) + f(b));
        
        for (int i = 1; i < n / 2; i++) {
            double x = a + i * h_half;
            sum_half += f(x);
        }
        
        double result_half = h_half * sum_half;
        result.error_estimate = std::abs(result.value - result_half);
    } else {
        result.error_estimate = 0.0; // Cannot estimate error with n < 2
    }
    
    return result;
}

} // namespace numerical
