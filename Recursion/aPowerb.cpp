/*
    Power a ^ b using recursion

*/

#include <iostream>
using namespace std;

int power(int m, int n) {

    //Time Complexity: O(n)
    // Aux space -> Stack space -> O(n) as there will be atmost (n + 1) recursive calls.
    if (n == 0)
        return 1; 
    return m * power(m, n-1); 
}
// efficient as there will be less multiplications in this code.
int power1(int m, int n) 
{
    if (n == 0)
        return 1; 
    
    if (n % 2 == 0) // If base is even, 
        return power1(m * m, n / 2);
    else 
        return m * power1(m * m, (n-1) / 2); 
}

int main() 
{
    int num, exponent; 
    cout << "Enter base and power separated by space:";
    cin >> num >> exponent;

    cout << power(num, exponent) << "\n"; 
    cout << power1(num, exponent) << "\n";

    return 0; 
}