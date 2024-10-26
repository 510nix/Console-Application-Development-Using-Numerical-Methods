// Arpita-2107021
#include <bits/stdc++.h>
#include "equation_types.hpp"
using namespace std;

class GaussSeidelIterative : public Linear
{
public:
    GaussSeidelIterative(int unknowns, const vector<vector<double>> &coefficients, double error) : Linear(unknowns, coefficients, error) {}
    void calculate() override
    {
        int n = this->unknowns;
        / Arpita Das /
            for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (this->coefficients[i][i] < this->coefficients[j][i])
                {
                    for (int k = 0; k <= n; k++)
                    {
                        swap(this->coefficients[i][k], this->coefficients[j][k]);
                    }
                    break;
                }
            }
        }
        vector<double> xp(n, 0.0);
        vector<double> xn(n);
        vector<double> ex(n);
        int steps = 100;
        do
        {
            for (int i = 0; i < n; i++)
            {
                xn[i] = ((double)1 / this->coefficients[i][i]) * this->coefficients[i][n];
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        continue;
                    xn[i] -= ((double)1 / this->coefficients[i][i]) * (xp[j] * this->coefficients[i][j]);
                }
                ex[i] = xn[i] - xp[i];
                xp[i] = xn[i];
            }
        } while (steps--);
        this->x = xn;
        this->showX();
    }
};
// Arpita-2107021
