/*Anika Nawer*/
#include <bits/stdc++.h>
#include "equation_types.hpp"
using namespace std;

class LUFactorization : public Linear {
protected:
    vector<vector<double>> L;
    vector<vector<double>> U;
    vector<double> y;
    void luDecomposition() {
        int n = this->unknowns;
        L = vector<vector<double>>(n, vector<double>(n, 0));
        U = vector<vector<double>>(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) L[i][i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                U[i][j] = this->coefficients[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i > j; i--) {
                double mul = abs(U[i][j] / U[j][j]);
                if (U[j][j] < 0 && U[i][j] > 0 ||
                    U[j][j] > 0 && U[i][j] < 0) {
                    L[i][j] = -mul;
                    for (int m = 0; m < n; m++) {
                        U[i][m] = U[i][m] + mul * U[j][m];
                    }
                } else {
                    L[i][j] = mul;
                    for (int m = 0; m < n; m++) {
                        U[i][m] = U[i][m] - mul * U[j][m];
                    }
                }
            }
        }
    }
    /*Anika Nawer*/
    void forwardSubstitution() {
        int n = this->unknowns;
        for (int i = 0; i < n; i++) {
            this->y[i] = this->coefficients[i][n];
            for (int j = 0; j < i; j++) {
                this->y[i] -= this->L[i][j] * this->y[j];
            }
        }
    }
    void backwardSubstitution() {
        int n = this->unknowns;
        for (int i = n - 1; i >= 0; i--) {
            this->x[i] = this->y[i];
            for (int j = i + 1; j < n; j++) {
                this->x[i] -= this->U[i][j] * this->x[j];
            }
            this->x[i] /= U[i][i];
        }
    }
    /*Anika Nawer*/
public:
    LUFactorization(int unknowns, const vector<vector<double>>& coefficients, double error) : Linear(unknowns, coefficients, error) {
        luDecomposition();
        y = vector<double>(this->unknowns);
    }
    void calculate() override {
        this->forwardSubstitution();
        this->backwardSubstitution();
        this->showX();
    }
};
/*Anika Nawer*/
