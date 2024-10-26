/*Anika Nawer*/
#include <bits/stdc++.h>
#include "equation_types.hpp"
using namespace std;

class BiSection : public NonLinear {
public:
    BiSection(int degree, const vector<int>& coefficients, double error) : NonLinear(degree, coefficients, error) {}
    void calculate() override {
        int xmax = abs(sqrt((this->coefficients[1] / this->coefficients[0]) * (this->coefficients[1] / this->coefficients[0]) -
                        2 * (this->coefficients[2] / this->coefficients[0]))) + 1;
        double _a = -xmax;
        double _b = xmax;
        int i = 1;
        while (i <= this->degree) {
            double a = 0.0;
            double b = 0.0;
            for (double i = _a; i < _b; i += 0.5) {
                if (this->f(i) * this->f(i + 1) <= 0.0) {
                    a = i;
                    b = i + 1;
                    _a = b + 0.5;
                    break;
                }
            }
            if (!(a == 0.0 && b == 0.0)) {
                bool flag = false;
                int steps = 100;
                double c;
                do {
                    double fa = this->f(a);
                    if (this->f(a) == 0.0) {
                        this->roots.push_back(a);
                        if (this->f(b) == 0.0) {
                            this->roots.push_back(b);
                            i++;
                        }
                        flag = true;
                        break;
                    }
                    c = ((double) a + b) / 2;
                    double fc = this->f(c);
                    if (fc == 0.0) break;
                    else if (fc * fa < 0.0) b = c;
                    else a = c;
                    if (b - a <= this->error) break;
                } while (steps--);
                if (!flag) this->roots.push_back(c);
            }
            i++;
        }
        this->showRoots();
    }
};
/*Anika Nawer*/
