/***
 * Fibonacci Series 
 * fib (n) = 0, if n == 0
 * fib(n) = 1, if n == 1
 * fib(n) = fib(n-1) + fib(n-2) if n > 1
*/

#include <iostream>

using namespace std;

int fibIterative(int n) {

    if (n <= 1)
        return n; 

    int t0 = 0, t1 = 1; 
    int s; 

    for (int i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
    // Time : O(n)


}
int fibRecursive(int n) {
    if (n <= 1)
        return n;
    return fibRecursive(n-1) + fibRecursive(n-2); 

    // Time : O(2 ^ n)
}
int main() {

    int n; cout << "Enter n: "; cin >> n; 

    cout << fibRecursive(n) << "\n";
    return 0; 
}
