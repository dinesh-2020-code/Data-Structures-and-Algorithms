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

//Efficient method with reduced multiplications - Horner's rule
double e1(int x, int n) {
    static double S = 1;
    if (n == 0)
        return S;
    
    S = 1 + (double) x / n * S;
    return e1(x, n-1); 
}

int main() 
{

    cout << e(1, 15) << "\n";
    cout << e1(1, 15) << "\n";
    return 0; 
}