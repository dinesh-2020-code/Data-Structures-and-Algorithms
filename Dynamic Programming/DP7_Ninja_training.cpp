/**
 * Problem Link: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
 * Problem statement
 * Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of
 * these three activities. (Running, Fighting Practice or Learning New Moves). Each activity 
 * has some merit points on each day. As Ninja has to improve all his skills, he can’t do the  
 * same activity in two consecutive days. Can you help Ninja find out the maximum merit points
 * Ninja can earn?
 * You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and
 * activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
 * For Example
 * If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
 * 
 * Constraints: 
            1 <= T <= 10
            1 <= N <= 100000.
            1 <= values of POINTS arrays <= 100
 * Input: N=4
 * points = 
        {
            {2, 1, 3},
            {3, 4, 6}, 
            {10, 1, 6},
            {8, 3, 7} 
        }

    Output: 25
*/


#include <iostream>

using namespace std; 


int ninjaTraining(int ind, int last, int points[][3]) {
    //Top Down approach memoisation: starting from the n-1 th day
    // ind is the ith day
    // last is the activity which was done on the last day (0, 1, 2), 
    // Initially there was no activity performed so we are taking 3 as last activity for (n-1)th Day
    // points is the array containing merit points for each activity on a particular day

    //base case
    if (ind == 0) {
        int maxi = 0;
        //take maximum of rest 2 days
        for (int i = 0; i <= 2; i++) {
            if (i != last)
                maxi = max(maxi, points[ind][i]);
        }
        return maxi; 
    }

    // Recursive case
    // check for all possible days other than last day
    int maxi = 0; 
    for (int i = 0; i <= 2; i++) {
        if (i != last) { // only take merit point if current ind and last are different
            maxi = max(maxi, (points[ind][i] + ninjaTraining(ind - 1, i, points)));
        }
    }
    return maxi; 

}

int main() {

    const int n = 4;
    int points[][3] = 
                        {
                            {2, 1, 3},
                            {3, 4, 6}, 
                            {10, 1, 6},
                            {8, 3, 7} 
                        };
    
    cout << "\n" << ninjaTraining(n - 1, 3, points) << "\n";
    return 0; 
}