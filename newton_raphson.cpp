#include "root_finding.h"

namespace numerical {

RootFindingResult newton_raphson(
    std::function<double(double)> f, 
    std::function<double(double)> df, 
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
        double fx = f(x);
        double dfx = df(x);
        
        // Check if derivative is close to zero to avoid division by zero
        if (std::abs(dfx) < 1e-10) {
            result.message = "Error: Derivative is too close to zero";
            result.root = x;
            result.error = error;
            return result;
        }
        
        double x_new = x - fx / dfx;
        error = std::abs(x_new - x);
        x = x_new;
        
        result.iterations++;
        
        if (error < tol || std::abs(fx) < tol) {
            result.converged = true;
            break;
        }
    }
    
    result.root = x;
    result.error = error;
    
    if (!result.converged) {
        result.message = "Warning: Maximum iterations reached without convergence";
    } else {
        result.message = "Success: Method converged to the root";
    }
    
    return result;
}

} // namespace numerical
