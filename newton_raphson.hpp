/*Zunaied Nudar*/
#include <bits/stdc++.h>
#include "equation_types.hpp"
using namespace std;

class NewtonRaphson : public NonLinear {
protected:
    double fp(double x) {
        double total = 0.0;
        for (int i = 0; i < this->degree; i++) {
            total += this->coefficients[i] * (this->degree - i) * pow(x, this->degree - i - 1);
        }
        return total;
    }
public:
    NewtonRaphson(int degree, const vector<int>& coefficients, double error) : NonLinear(degree, coefficients, error) {}
    void calculate() override {
        int xmax = abs(sqrt((this->coefficients[1] / this->coefficients[0]) * (this->coefficients[1] / this->coefficients[0]) - 
                        2 * (this->coefficients[2] / this->coefficients[0]))) + 1;
        double _a = -xmax;
        double _b = xmax;
        int i = 1;
        while (i <= this->degree) {
            int steps = 100;
            double x0 = _a, x1, f0, f0p;
            _a += 0.5;
            do {
                f0 = this->f(x0);
                f0p = this->fp(x0);
                if (f0p == 0.0) break;
                x1 = x0 - f0 / f0p;
                x0 = x1;
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
