#include "root_finding.h"

namespace numerical {

RootFindingResult bisection(
    std::function<double(double)> f, 
    double a, 
    double b, 
    double tol, 
    int max_iter
) {
    RootFindingResult result;
    result.iterations = 0;
    result.converged = false;
    
    // Check if the function changes sign in the interval
    double fa = f(a);
    double fb = f(b);
    
    if (fa * fb > 0) {
        result.message = "Error: Function does not change sign in the given interval";
        return result;
    }
    
    double c, fc;
    double error = b - a;
    
    for (int i = 0; i < max_iter; i++) {
        error = (b - a) / 2;
        c = a + error;
        fc = f(c);
        
        result.iterations++;
        
        if (std::abs(error) < tol || std::abs(fc) < tol) {
            result.converged = true;
            break;
        }
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    
    result.root = c;
    result.error = std::abs(error);
    
    if (!result.converged) {
        result.message = "Warning: Maximum iterations reached without convergence";
    } else {
        result.message = "Success: Method converged to the root";
    }
    
    return result;
}

} // namespace numerical
