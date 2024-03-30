/**
 * Problem Link: https://www.naukri.com/code360/problems/cost-to-cut-a-chocolate_3208460
 * Problem statement
 * You are given chocolate of ‘N’ length. The chocolate is labeled from 0 to ‘N’. You are also 
 * given an array ‘CUTS’ of size ‘C’, denoting the positions at which you can do a cut. The order 
 * of cuts can be changed. The cost of one cut is the length of the chocolate to be cut. Therefore, 
 * the total cost is the sum of all the cuts. Print the minimum cost to cut the chocolate.
 * Note:
 *      All the integers in the ‘CUTS’ array are distinct.
 * For example:
 *  Let ‘N’ be: 4
 *  Let the ‘CUTS’ array be: [1, 3].
 *  Let the order of doing the cut be [1, 3].
 *  The first cut of 1 on length 4 results in a cost of 4, and chocolate is split into two parts of the 
 *  length of 1 and 3.
 *  The second cut of 3 on length 3 results in a cost of 3, and chocolate is split into two parts again 
 *  of the length of 2 and 1. So the total cost is 7.
 *  The cost will remain the same if we change the order of cutting. So the result is 7.
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int minCost(int i, int j, vector<int> &cuts, vector<vector<int> > &dp) {
    if (i > j)  
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++) {
        int cost = cuts[j + 1] - cuts[i - 1] + minCost(i, ind - 1, cuts, dp)
                 + minCost(ind + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;    
}


int memoizedSol(vector<int> &cuts, int n) {

    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int> > dp (c + 1, vector<int> (c + 1, -1));
    cout << "Min cost is: " << minCost(1, c, cuts, dp) << endl;
}


int main() {

    vector<int> cuts = {1, 3, 4, 5};
    int n = 7;
    return memoizedSol(cuts, n);

}