/**
 * Code to printNto1 using recursion
 * 
*/

#include <iostream>
using namespace std;

void printNto1(int n) {
    //base case
    if (n == 0)
        return;

    cout << n << " ";
    //Recursive call
    printNto1(n-1); 
}

int main() 
{
    int n; 
    cout << "Enter n: ";
    cin >> n; 

    printNto1(n);

    return 0; 
}

/*
    Time complexity: 
        Recurrence Relation: T(n) = T(n-1) + 1 => After solving it
        Time complexity is O(n), where n is the input number.
    
    Auxiliary space: 
        Recursive stack space: Atmost (n + 1) function calls will be there in the recursive stack. 
        So auxiliary  space would be O(n)
*/
