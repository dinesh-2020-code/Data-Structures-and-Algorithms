/**
 * Tower of Hanoi Problem
 * Problem Link: https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1
 * 
 *  TOH(N, A, B, C)  A -> src, B -> Aux. tower, C -> Dest
 *  {
 *      1. TOH(N-1, A, C, B) => Move N-1 disks from A to B(aux tower) using C as auxiliary tower
 *      2. Move 1 remaining disk from A to C using B
 *      3. TOH(N-1, B, A, C) => Move N-1 disks from B to C using A as aux tower.
 *  }
 *  total no. of steps: (2 ^ n) - 1 For ex: for n = 3, total steps = 2 ^ 3 -1 = 7 steps
 *  No. of calls: 2 ^ (n + 1) - 1. For ex: for n = 3 disks, total no of calls will be 2 ^ 4 - 1 = 15
 *  Time complexity: O(2^n)
 * 
*/

#include <iostream>
using namespace std;

void TOH(int n, char beg, char aux, char end) {

    if (n > 0) {
        TOH(n-1, beg, end, aux);
        cout << "Move 1 disk from " << beg << " to " << end << "\n"; 
        TOH(n-1, aux, beg, end); 
    }
}

int main() 
{
    cout << "Enter no. of disks: ";
    int n; cin >> n; 
    char beg, aux, end; 
    cin >> beg >> aux >> end; 
    TOH(n, beg, aux, end);

    return 0; 
}