#include "integration.h"

namespace numerical {

IntegrationResult simpsons_rule(
    std::function<double(double)> f, 
    double a, 
    double b, 
    int n
) {
    IntegrationResult result;
    
    if (n <= 0) {
        throw std::invalid_argument("Number of intervals must be positive");
    }
    
    if (n % 2 != 0) {
        n++; // Ensure n is even for Simpson's rule
        result.message = "Warning: Number of intervals must be even for Simpson's rule. Adjusted to " + std::to_string(n);
    } else {
        result.message = "Success: Simpson's 1/3 rule applied successfully";
    }
    
    if (a > b) {
        // Swap a and b if a > b
        std::swap(a, b);
        result.message = "Warning: Lower bound greater than upper bound. Bounds were swapped.";
    }
    
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    // Sum for points with odd indices (coefficient 4)
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }
    
    // Sum for points with even indices (coefficient 2)
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    
    result.value = (h / 3) * sum;
    
    // Simple error estimate based on halving the number of intervals
    if (n >= 4) {
        int n_half = n / 2;
        if (n_half % 2 != 0) n_half++; // Ensure n_half is even
        
        double h_half = (b - a) / n_half;
        double sum_half = f(a) + f(b);
        
        // Sum for points with odd indices (coefficient 4)
        for (int i = 1; i < n_half; i += 2) {
            double x = a + i * h_half;
            sum_half += 4 * f(x);
        }
        
        // Sum for points with even indices (coefficient 2)
        for (int i = 2; i < n_half; i += 2) {
            double x = a + i * h_half;
            sum_half += 2 * f(x);
        }
        
        double result_half = (h_half / 3) * sum_half;
        result.error_estimate = std::abs(result.value - result_half);
    } else {
        result.error_estimate = 0.0; // Cannot estimate error with n < 4
    }
    
    return result;
}

} // namespace numerical
