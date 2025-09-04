#include "interpolation.h"

namespace numerical {

std::vector<std::vector<double>> divided_difference_table(
    const std::vector<double>& x, 
    const std::vector<double>& y
) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("x and y vectors must have the same size");
    }
    
    if (x.size() == 0) {
        throw std::invalid_argument("Input vectors cannot be empty");
    }
    
    size_t n = x.size();
    std::vector<std::vector<double>> table(n, std::vector<double>(n, 0.0));
    
    // Fill the first column with y values
    for (size_t i = 0; i < n; i++) {
        table[i][0] = y[i];
    }
    
    // Calculate the divided differences
    for (size_t j = 1; j < n; j++) {
        for (size_t i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    
    return table;
}

std::function<double(double)> newton_divided_difference(
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
        return newton_divided_difference_evaluate(x, y, x_point);
    };
}

double newton_divided_difference_evaluate(
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
    
    std::vector<std::vector<double>> table = divided_difference_table(x, y);
    
    double result = table[0][0];
    double term = 1.0;
    
    for (size_t i = 1; i < x.size(); i++) {
        term *= (x_point - x[i - 1]);
        result += term * table[0][i];
    }
    
    return result;
}

} // namespace numerical
