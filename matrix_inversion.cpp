// Arpita-2107021
#include <bits/stdc++.h>
#include "equation_types.hpp"
using namespace std;

class MatrixInversion : public Linear
{
protected:
    int order;
    void showInverseMatrix()
    {
        for (int i = 0; i < this->order; i++)
        {
            for (int j = this->order; j < 2 * this->order; j++)
            {
                cout << this->coefficients[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    / Arpita Das /
        void swapp(vector<vector<double>> &mat)
    {
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            if (mat[i][i] == 0)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (mat[j][i] != 0)
                    {
                        swap(mat[i], mat[j]);
                        break;
                    }
                }
            }
        }
    }
    vector<vector<double>> gauss_eli(vector<vector<double>> mat)
    {
        swapp(mat);
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            if (mat[i][i] != 0)
            {
                for (int j = i + 1; j < n; j++)
                {
                    double factor = mat[j][i] / mat[i][i];
                    for (int k = 0; k < n + this->order; k++)
                    {
                        mat[j][k] -= mat[i][k] * factor;
                    }
                }
            }
        }
        return mat;
    }
    vector<vector<double>> gauss_jordan(vector<vector<double>> mat)
    {
        int n = mat.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (mat[i][i] != 0)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    double factor = mat[j][i] / mat[i][i];
                    for (int k = n + this->order - 1; k >= 0; k--)
                    {
                        mat[j][k] -= mat[i][k] * factor;
                    }
                }
            }
        }
        return mat;
    }
    vector<vector<double>> rref(vector<vector<double>> mat)
    {
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            double factor = mat[i][i];
            if (factor != 0)
            {
                for (int j = 0; j < n + this->order; j++)
                {
                    mat[i][j] /= factor;
                }
            }
        }
        return mat;
    }

public:
    MatrixInversion(vector<vector<double>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (n != m)
        {
            cout << "Invalid Matrix\n";
            exit(1);
        }
        this->order = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    matrix[i].push_back(1);
                else
                    matrix[i].push_back(0);
            }
        }
        this->coefficients = matrix;
    }

    // Zunaid-2107021
    // added the override keyword
    void calculate() override
    { // Zunaid-2107021
        this->coefficients = this->gauss_eli(this->coefficients);
        this->coefficients = this->gauss_jordan(this->coefficients);
        this->coefficients = this->rref(this->coefficients);
        this->showInverseMatrix();
    }
};
// Arpita-2107021
