#include <iostream>
#include <vector>

using namespace std;

pair<double, double> linearLeastSquares(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double a = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double b = (sum_y - a * sum_x) / n;

    return {a, b}; // (slope, intercept)
}

int main() {
    vector<double> x = {1, 2, 3, 4, 5};
    vector<double> y = {2, 4.1, 6.1, 8, 10.1};

    auto [a, b] = linearLeastSquares(x, y);

    cout << "Best fit line: y = " << a << "x + " << b << endl;

    return 0;
}
