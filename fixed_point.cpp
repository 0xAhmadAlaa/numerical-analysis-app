#include "root_finding.h"

namespace numerical {

RootFindingResult fixed_point(
    std::function<double(double)> g, 
    double x0, 
    double tol, 
    int max_iter
) {
    RootFindingResult result;
    result.iterations = 0;
    result.converged = false;
    
    double x = x0;
    double error = tol + 1; // Initialize error to be greater than tolerance
    
    for (int i = 0; i < max_iter; i++) {
        double x_new = g(x);
        error = std::abs(x_new - x);
        x = x_new;
        
        result.iterations++;
        
        if (error < tol) {
            result.converged = true;
            break;
        }
    }
    
    result.root = x;
    result.error = error;
    
    if (!result.converged) {
        result.message = "Warning: Maximum iterations reached without convergence";
    } else {
        result.message = "Success: Method converged to the fixed point";
    }
    
    return result;
}

} // namespace numerical
