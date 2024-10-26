/*Zunaied Nudar*/
/*Arpita Das*/
/*Anika Nawer*/
#include <bits/stdc++.h>
#include "jacobi_iterative.hpp"
#include "gauss_seidel_iterative.hpp"
#include "gauss_jordan_elimination.hpp"
#include "lu_factorization.hpp"
#include "bi_section.hpp"
#include "false_position.hpp"
#include "secant.hpp"
#include "newton_raphson.hpp"
#include "runge_kutta.hpp"
#include "matrix_inversion.hpp"
using namespace std;

void LE();
void NLE();
void MI();

int main() {
    for (;;) {
        cout << "Choose one of the following actions:\n\n";
        cout << "1. Solve Linear Equations\n";
        cout << "2. Solve Non-linear Equations\n";
        cout << "3. Solve Differential Equations\n";
        cout << "4. Matrix Inversion\n";
        cout << "0. Exit\n\n";
        cout << "Choice?    ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                LE();
                break;
            case 2:
                NLE();
                break;
            case 3:
                DE();
                break;
            case 4:
                MI();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice...\n";
        }
    }
    
    return 0;
}

void LE() {
    cout << "Enter the number of unknowns:  ";
    int unknowns;
    cin >> unknowns;
    int n = unknowns;
    vector<vector<double>> coefficients(n, vector<double>(n + 1));
    double error = 0.000001;
    cout << "\nEnter all of the coefficients:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cin >> coefficients[i][j];
        }
    }
    Linear* jacobiIterative = new JacobiIterative(unknowns, coefficients, error);
    Linear* gaussSeidelIterative = new GaussSeidelIterative(unknowns, coefficients, error);
    Linear* luFactorization = new LUFactorization(unknowns, coefficients, error);
    
    /*Arpita Das*/
    cout << "\nGauss Elimination:\n";
    gauss_elimination(coefficients);
    vector<vector<double>> result1 = gauss_eli(coefficients);
    vector<vector<double>> result2 = gauss_jordan(result1);
    cout << "\nGauss-Jordan Elimination:\n";
    vector<vector<double>> result3 = rref(result2);
    int r = result3.size();
    int c = result3[0].size();
    for (int i = 0; i < r; i++) {
        cout << result3[i][c - 1] << " ";
    }
    cout << "\n";
    
    cout << "\nJacobi Iterative:\n";
    jacobiIterative->calculate();
    cout << "\nGauss-Seidel Iterative:\n";
    gaussSeidelIterative->calculate();
    cout << "\nLU Factorization:\n";
    luFactorization->calculate();
    cout << "\n\n\n";
}

void NLE() {
    cout << setprecision(3) << fixed;
    cout << "Enter the degree of polynomial:  ";
    int degree;
    cin >> degree;
    int n = degree;
    vector<int> coefficients(n + 1);
    double error = 0.000001;
    cout << "\nEnter all of the coefficients:\n";
    for (int i = 0; i < n + 1; i++) {
        cin >> coefficients[i];
    }
    NonLinear* biSection = new BiSection(degree, coefficients, error);
    NonLinear* falsePosition = new FalsePosition(degree, coefficients, error);
    NonLinear* secant = new Secant(degree, coefficients, error);
    NonLinear* newtonRaphson = new NewtonRaphson(degree, coefficients, error);
    cout << "\nBi-Section:\n";
    biSection->calculate();
    cout << "\nFalse Position:\n";
    falsePosition->calculate();
    cout << "\nSecant:\n";
    secant->calculate();
    cout << "\nNewton-Raphson:\n";
    newtonRaphson->calculate();
    cout << "\n\n\n";
}

void MI() {
    cout << "Enter the order of the matrix:  ";
    int order;
    cin >> order;
    vector<vector<double>> matrix(order, vector<double>(order));
    cout << "\nEnter all of the elements:\n";
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            cin >> matrix[i][j];
        }
    }
    Linear* matrixInversion = new MatrixInversion(matrix);
    cout << "\nMatrix Inversion:\n";
    matrixInversion->calculate();
    cout << "\n\n\n";
}
/*Zunaied Nudar*/
/*Arpita Das*/
/*Anika Nawer*/

