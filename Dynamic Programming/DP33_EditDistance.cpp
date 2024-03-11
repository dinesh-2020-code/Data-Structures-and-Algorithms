/**
 * Problem: Edit Distance
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


int editDistances (int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    //Time complexity: O (m * n)
    //Aux Space: O (m * n) + O (m + n)

    //base cases
    // case 1: If string s1 got exhausted (i < 0)
    // min operations required to convert an empty string to some string s2[0..j] is j + 1
    if (i < 0)
        return j + 1;
    //case 2: If string s2 got exhausted (j < 0)
    // min operations required to convert string s1[0..i] to an empty string is i + 1 (u reqd to delete i + 1 chars from s1)
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    //recursive cases
    // case 1: if char at s1[i] and s2[j] matched
    if (s1[i] == s2[j])
        return dp[i][j] = 0 + editDistances(i - 1, j - 1, s1, s2, dp);
    else {    // case 2: chars not matching, we have 3 sub-operations (insert, delete, replace)
        int ins = 1 + editDistances(i, j - 1, s1, s2, dp);
        int del = 1 + editDistances(i - 1, j, s1, s2, dp);
        int rep = 1 + editDistances(i - 1, j - 1, s1, s2, dp);
        //returns min of all operations
        return dp[i][j] = min (ins, min (del, rep));
    }
}


int memoisedSol(string &s1, string &s2) {

    int m = s1.size();
    int n = s2.size();

    vector<vector<int> > dp (m, vector<int> (n, -1));
    return editDistances(m - 1, n - 1, s1, s2, dp);
}


int main () {

    string s1, s2;
    cout << "Enter two strings separated by spaces\n";
    cin >> s1 >> s2;

    cout << memoisedSol(s1, s2);

    return 0;
}

