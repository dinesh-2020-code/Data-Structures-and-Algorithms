/**
 * Code to print1ToN using recursion

*/

#include <iostream>
using namespace std;

void print1ToN(int n) {
    if (n == 0)
        return

    print1ToN(n-1); 
    cout << n << " ";
}

int main() 
{
    int n; 
    cout << "Enter n: ";
    cin >> n; 

    print1ToN(n);

    return 0; 
}