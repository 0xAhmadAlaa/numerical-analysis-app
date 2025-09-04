#include "root_finding.h"

namespace numerical {

RootFindingResult secant(
    std::function<double(double)> f, 
    double x0, 
    double x1, 
    double tol, 
    int max_iter
) {
    RootFindingResult result;
    result.iterations = 0;
    result.converged = false;
    
    double x_prev = x0;
    double x_curr = x1;
    double f_prev = f(x_prev);
    double f_curr = f(x_curr);
    double error = std::abs(x_curr - x_prev);
    
    for (int i = 0; i < max_iter; i++) {
        // Check if denominator is close to zero to avoid division by zero
        if (std::abs(f_curr - f_prev) < 1e-10) {
            result.message = "Error: Division by near-zero value";
            result.root = x_curr;
            result.error = error;
            return result;
        }
        
        double x_next = x_curr - f_curr * (x_curr - x_prev) / (f_curr - f_prev);
        error = std::abs(x_next - x_curr);
        
        x_prev = x_curr;
        f_prev = f_curr;
        x_curr = x_next;
        f_curr = f(x_curr);
        
        result.iterations++;
        
        if (error < tol || std::abs(f_curr) < tol) {
            result.converged = true;
            break;
        }
    }
    
    result.root = x_curr;
    result.error = error;
    
    if (!result.converged) {
        result.message = "Warning: Maximum iterations reached without convergence";
    } else {
        result.message = "Success: Method converged to the root";
    }
    
    return result;
}

} // namespace numerical
