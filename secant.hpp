/*Zunaied Nudar*/
#include <bits/stdc++.h>
#include "equation_types.hpp"
using namespace std;

class Secant : public NonLinear {
public:
    Secant(int degree, const vector<int>& coefficients, double error) : NonLinear(degree, coefficients, error) {}
    void calculate() override {
        int xmax = abs(sqrt((this->coefficients[1] / this->coefficients[0]) * (this->coefficients[1] / this->coefficients[0]) - 
                        2 * (this->coefficients[2] / this->coefficients[0]))) + 1;
        double _a = -xmax;
        double _b = xmax;
        int i = 1;
        while (i <= this->degree) {
            int steps = 100;
            double x0 = _a, x1 = _a + 0.5, x2, f0, f1, f2;
            _a += 0.5;
            do {
                f0 = this->f(x0);
                f1 = this->f(x1);
                if (f1 - f0 == 0.0) break;
                x2 = x1 - ((f1 * (x1 - x0)) / (f1 - f0));
                f2 = this->f(x2);
                x0 = x1;
                x1 = x2;
                if (abs(x1 - x0) <= this->error) break;
            } while (steps--);
            bool isSimilar = false;
            for (auto& root : this->roots) {
                if (abs(root - x1) < 0.5) isSimilar = true;
            }
            if (!isSimilar) {
                this->roots.push_back(x1);
                i++;
            }
            if (_a == _b) break;
        }
        this->showRoots();
    }
};
/*Zunaied Nudar*/
