/**
 * Taylor series: 
 *      e ^ x = 1 + (x / 1) + ((x ^ 2) / 2!) + ((x ^ 3) / 3!) + .... + ((x ^ (n-1)) / (n-1!) + ((x ^ n) / n!)
 * 
*/

#include <iostream>
using namespace std;

static double P = 1, F = 1;

double e(int x, int n) {
    double r; 

    if (n == 0)
        return 1;

    else {
        r = e(x, n-1);
        P = P * x; 
        F = F * n; 
        return r + P/F;
    }
}

int main() 
{

    cout << e(1, 15) << "\n";

    return 0; 
}