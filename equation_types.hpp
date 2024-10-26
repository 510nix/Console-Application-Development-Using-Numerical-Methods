/*Zunaied Nudar*/
#pragma once
#include <bits/stdc++.h>
using namespace std;

class NonLinear {
protected:
    int degree;
    vector<int> coefficients;
    double error;
    vector<double> roots;
    double f(double x) {
        double total = 0.0;
        for (int i = 0; i < this->degree + 1; i++) {
            total += this->coefficients[i] * pow(x, this->degree - i);
        }
        return total;
    }
public:
    NonLinear(int degree, const vector<int>& coefficients, double error) : degree(degree), coefficients(coefficients), error(error) {}
    virtual void calculate() {}
    void showRoots() {
        for (auto& root : this->roots) cout << root << " ";
        cout << "\n";
    }
};

class Linear {
protected:
    int unknowns;
    vector<vector<double>> coefficients;
    double error;
    vector<double> x;
public:
    Linear(int unknowns, const vector<vector<double>>& coefficients, double error) : unknowns(unknowns), coefficients(coefficients), error(error) {
        this->x = vector<double>(unknowns, 0);
    }
    Linear() : error(0) {}
    virtual void calculate() {}
    void showX() {
        for (auto& val : x) cout << val << " ";
        cout << "\n";
    }
    void print() {
        for (auto& i : this->coefficients) {
            for (auto& j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};
/*Zunaied Nudar*/
