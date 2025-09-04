#include <iostream>
#include <functional>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
#include <memory>

#include "numerical_analysis.h"

using namespace numerical;
using namespace std;

// Forward declarations
void displayMainMenu();
void handleRootFinding();
void handleInterpolation();
void handleIntegration();
void displayRootFindingMenu();
void displayInterpolationMenu();
void displayIntegrationMenu();
void handleBisection();
void handleNewtonRaphson();
void handleSecant();
void handleFixedPoint();
void handleLagrangeInterpolation();
void handleNewtonDividedDifference();
void handleTrapezoidalRule();
void handleSimpsonsRule();

// Example functions for testing
double exampleFunction1(double x) {
    return x*x - 2*x - 3; // f(x) = x² - x - 3

}

double exampleFunction1Derivative(double x) {
    return 3*x*x - 2; // f'(x) = 3x² - 2
}

double exampleFunction2(double x) {
    return sin(x) - 0.5*x; // f(x) = sin(x) - 0.5x
}

double exampleFunction2Derivative(double x) {
    return cos(x) - 0.5; // f'(x) = cos(x) - 0.5
}

double fixedPointFunction(double x) {
    return  1 / sqrt(x + 1); // f(x) = x³ + x² - 1  Define g(x) = 1 / sqrt(x + 1)

}

int main() {
    cout << "=======================================" << endl;
    cout << "   Numerical Analysis Application      " << endl;
    cout << "=======================================" << endl;
    cout << "             0xAhmadAlaa               " << endl;
    cout << "=======================================" << endl;
   
    bool running = true;
    while (running) {
        displayMainMenu();
        
        int choice;
        cout << "Enter your choice (0-4): ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 0:
                running = false;
                break;
            case 1:
                handleRootFinding();
                break;
            case 2:
                handleInterpolation();
                break;
            case 3:
                handleIntegration();
                break;
            case 4:
                cout << "\nAbout this application:" << endl;
                cout << "This application implements various numerical methods for:" << endl;
                cout << "- Root finding (Bisection, Newton-Raphson, Secant, Fixed Point)" << endl;
                cout << "- Interpolation (Lagrange, Newton's Divided Difference)" << endl;
                cout << "- Numerical Integration (Trapezoidal Rule, Simpson's 1/3 Rule)" << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    cout << "Thank you for using the Numerical Analysis Application!" << endl;
    return 0;
}

void displayMainMenu() {
    cout << "\nMain Menu:" << endl;
    cout << "1. Root Finding Methods" << endl;
    cout << "2. Interpolation Methods" << endl;
    cout << "3. Numerical Integration Methods" << endl;
    cout << "4. About" << endl;
    cout << "0. Exit" << endl;
}

void handleRootFinding() {
    bool submenu = true;
    while (submenu) {
        displayRootFindingMenu();
        
        int choice;
        cout << "Enter your choice (0-4): ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 0:
                submenu = false;
                break;
            case 1:
                handleBisection();
                break;
            case 2:
                handleNewtonRaphson();
                break;
            case 3:
                handleSecant();
                break;
            case 4:
                handleFixedPoint();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void displayRootFindingMenu() {
    cout << "\nRoot Finding Methods:" << endl;
    cout << "1. Bisection Method" << endl;
    cout << "2. Newton-Raphson Method" << endl;
    cout << "3. Secant Method" << endl;
    cout << "4. Fixed Point Iteration" << endl;
    cout << "0. Back to Main Menu" << endl;
}

void handleInterpolation() {
    bool submenu = true;
    while (submenu) {
        displayInterpolationMenu();
        
        int choice;
        cout << "Enter your choice (0-2): ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 0:
                submenu = false;
                break;
            case 1:
                handleLagrangeInterpolation();
                break;
            case 2:
                handleNewtonDividedDifference();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void displayInterpolationMenu() {
    cout << "\nInterpolation Methods:" << endl;
    cout << "1. Lagrange Interpolation" << endl;
    cout << "2. Newton's Divided Difference Interpolation" << endl;
    cout << "0. Back to Main Menu" << endl;
}

void handleIntegration() {
    bool submenu = true;
    while (submenu) {
        displayIntegrationMenu();
        
        int choice;
        cout << "Enter your choice (0-2): ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 0:
                submenu = false;
                break;
            case 1:
                handleTrapezoidalRule();
                break;
            case 2:
                handleSimpsonsRule();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void displayIntegrationMenu() {
    cout << "\nNumerical Integration Methods:" << endl;
    cout << "1. Trapezoidal Rule" << endl;
    cout << "2. Simpson's 1/3 Rule" << endl;
    cout << "0. Back to Main Menu" << endl;
}

void handleBisection() {
    cout << "\nBisection Method" << endl;
    cout << "Example function:  f(x) = x² - x - 3" << endl;
    
    double a, b;
    double tol;
    int max_iter;
    
    cout << "Enter lower bound (a): ";
    cin >> a;
    cout << "Enter upper bound (b): ";
    cin >> b;
    cout << "Enter tolerance (default: 1e-6): ";
    cin >> tol;
    cout << "Enter maximum iterations (default: 100): ";
    cin >> max_iter;
    
    try {
        RootFindingResult result = bisection(exampleFunction1, a, b, tol, max_iter);
        
        cout << "\nResults:" << endl;
        cout << "Root: " << result.root << endl;
        cout << "Function value at root: " << exampleFunction1(result.root) << endl;
        cout << "Iterations: " << result.iterations << endl;
        cout << "Error: " << result.error << endl;
        cout << "Status: " << result.message << endl;
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void handleNewtonRaphson() {
    cout << "\nNewton-Raphson Method" << endl;
    cout << "Example function: f(x) = x³ - 2x - 5" << endl;
    cout << "Derivative: f'(x) = 3x² - 2" << endl;
    
    double x0;
    double tol;
    int max_iter;
    
    cout << "Enter initial guess (x0): ";
    cin >> x0;
    cout << "Enter tolerance (default: 1e-6): ";
    cin >> tol;
    cout << "Enter maximum iterations (default: 100): ";
    cin >> max_iter;
    
    try {
        RootFindingResult result = newton_raphson(exampleFunction1, exampleFunction1Derivative, x0, tol, max_iter);
        
        cout << "\nResults:" << endl;
        cout << "Root: " << result.root << endl;
        cout << "Function value at root: " << exampleFunction1(result.root) << endl;
        cout << "Iterations: " << result.iterations << endl;
        cout << "Error: " << result.error << endl;
        cout << "Status: " << result.message << endl;
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void handleSecant() {
    cout << "\nSecant Method" << endl;
    cout << "Example function: f(x) = sin(x) - 0.5x" << endl;
    
    double x0, x1;
    double tol;
    int max_iter;
    
    cout << "Enter first initial guess (x0): ";
    cin >> x0;
    cout << "Enter second initial guess (x1): ";
    cin >> x1;
    cout << "Enter tolerance (default: 1e-6): ";
    cin >> tol;
    cout << "Enter maximum iterations (default: 100): ";
    cin >> max_iter;
    
    try {
        RootFindingResult result = secant(exampleFunction2, x0, x1, tol, max_iter);
        
        cout << "\nResults:" << endl;
        cout << "Root: " << result.root << endl;
        cout << "Function value at root: " << exampleFunction2(result.root) << endl;
        cout << "Iterations: " << result.iterations << endl;
        cout << "Error: " << result.error << endl;
        cout << "Status: " << result.message << endl;
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void handleFixedPoint() {
    cout << "\nFixed Point Iteration" << endl;
    cout << "Example function:f(x) = x³ + x² - 1  so g(x) = 1 / sqrt(x + 1)" << endl;
    
    double x0;
    double tol;
    int max_iter;
    
    cout << "Enter initial guess (x0): ";
    cin >> x0;
    cout << "Enter tolerance (default: 1e-6): ";
    cin >> tol;
    cout << "Enter maximum iterations (default: 100): ";
    cin >> max_iter;
    
    try {
        RootFindingResult result = fixed_point(fixedPointFunction, x0, tol, max_iter);
        
        cout << "\nResults:" << endl;
        cout << "Fixed Point: " << result.root << endl;
        cout << "g(x) at fixed point: " << fixedPointFunction(result.root) << endl;
        cout << "Iterations: " << result.iterations << endl;
        cout << "Error: " << result.error << endl;
        cout << "Status: " << result.message << endl;
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void handleLagrangeInterpolation() {
    cout << "\nLagrange Interpolation" << endl;
    
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    
    if (n < 2) {
        cout << "Error: At least 2 data points are required." << endl;
        return;
    }
    
    vector<double> x(n), y(n);
    
    cout << "Enter data points (x, y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Point " << i+1 << " - x: ";
        cin >> x[i];
        cout << "Point " << i+1 << " - y: ";
        cin >> y[i];
    }
    
    double x_eval;
    cout << "Enter x value to evaluate the polynomial: ";
    cin >> x_eval;
    
    try {
        double result = lagrange_evaluate(x, y, x_eval);
        
        cout << "\nResults:" << endl;
        cout << "Interpolated value at x = " << x_eval << ": " << result << endl;
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void handleNewtonDividedDifference() {
    cout << "\nNewton's Divided Difference Interpolation" << endl;
    
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    
    if (n < 2) {
        cout << "Error: At least 2 data points are required." << endl;
        return;
    }
    
    vector<double> x(n), y(n);
    
    cout << "Enter data points (x, y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Point " << i+1 << " - x: ";
        cin >> x[i];
        cout << "Point " << i+1 << " - y: ";
        cin >> y[i];
    }
    
    double x_eval;
    cout << "Enter x value to evaluate the polynomial: ";
    cin >> x_eval;
    
    try {
        double result = newton_divided_difference_evaluate(x, y, x_eval);
        
        cout << "\nResults:" << endl;
        cout << "Interpolated value at x = " << x_eval << ": " << result << endl;
        
        // Display the divided difference table
        cout << "\nDivided Difference Table:" << endl;
        auto table = divided_difference_table(x, y);
        
        cout << setw(10) << "x";
        for (size_t i = 0; i < table[0].size(); i++) {
            cout << setw(15) << "f[" << i << "]";
        }
        cout << endl;
        
        for (size_t i = 0; i < table.size(); i++) {
            cout << setw(10) << x[i];
            for (size_t j = 0; j < table[i].size(); j++) {
                if (j <= i) {
                    cout << setw(15) << table[i-j][j];
                } else {
                    cout << setw(15) << "";
                }
            }
            cout << endl;
        }
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void handleTrapezoidalRule() {
    cout << "\nTrapezoidal Rule" << endl;
    cout << "Example function: f(x) = sin(x)" << endl;
    
    auto integrand = [](double x) { return sin(x); };
    
    double a, b;
    int n;
    
    cout << "Enter lower bound (a): ";
    cin >> a;
    cout << "Enter upper bound (b): ";
    cin >> b;
    cout << "Enter number of intervals (n): ";
    cin >> n;
    
    try {
        IntegrationResult result = trapezoidal_rule(integrand, a, b, n);
        
        cout << "\nResults:" << endl;
        cout << "Integral value: " << result.value << endl;
        cout << "Error estimate: " << result.error_estimate << endl;
        cout << "Status: " << result.message << endl;
        
        // Compare with exact solution for sin(x)
        double exact = -cos(b) + cos(a);
        cout << "Exact value: " << exact << endl;
        cout << "Absolute error: " << std::abs(result.value - exact) << endl;
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void handleSimpsonsRule() {
    cout << "\nSimpson's 1/3 Rule" << endl;
    cout << "Example function: f(x) = sin(x)" << endl;
    
    auto integrand = [](double x) { return sin(x); };
    
    double a, b;
    int n;
    
    cout << "Enter lower bound (a): ";
    cin >> a;
    cout << "Enter upper bound (b): ";
    cin >> b;
    cout << "Enter number of intervals (n, must be even): ";
    cin >> n;
    
    try {
        IntegrationResult result = simpsons_rule(integrand, a, b, n);
        
        cout << "\nResults:" << endl;
        cout << "Integral value: " << result.value << endl;
        cout << "Error estimate: " << result.error_estimate << endl;
        cout << "Status: " << result.message << endl;
        
        // Compare with exact solution for sin(x)
        double exact = -cos(b) + cos(a);
        cout << "Exact value: " << exact << endl;
        cout << "Absolute error: " << std::abs(result.value - exact) << endl;
    }
    catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
