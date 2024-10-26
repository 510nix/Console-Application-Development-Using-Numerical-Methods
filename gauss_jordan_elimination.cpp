// Arpita-2107021
#include <bits/stdc++.h>
using namespace std;

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

void gauss_elimination(vector<vector<double>> &mat)
{
    swapp(mat);
    int n = mat.size();
    vector<double> result(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double factor = mat[j][i] / mat[i][i];
            for (int k = 0; k <= n; k++)
            {
                mat[j][k] -= (factor * mat[i][k]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] = mat[i][n];
        for (int j = i + 1; j < n; j++)
        {
            result[i] -= (mat[i][j] * result[j]);
        }
        result[i] /= mat[i][i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
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
                for (int k = 0; k <= n; k++)
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
                for (int k = n; k >= 0; k--)
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
            for (int j = 0; j <= n; j++)
            {
                mat[i][j] /= factor;
            }
        }
    }
    return mat;
}

void check_solution(vector<vector<double>> mat)
{
    int n = mat.size();
    bool infinite = false;
    bool no_solve = false;

    for (int i = 0; i < n; i++)
    {
        bool all_zero = true;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                all_zero = false;
                break;
            }
        }
        if (all_zero && mat[i][n] == 0)
        {
            infinite = true;
        }
        else if (all_zero && mat[i][n] != 0)
        {
            no_solve = true;
            break;
        }
    }

    if (no_solve)
    {
        cout << "No solutions exist." << endl;
    }
    else if (infinite)
    {
        cout << "System has infinite solutions." << endl;
    }
    else
    {
        cout << "System has a unique solution." << endl;
    }
}
// Arpita-2107021
