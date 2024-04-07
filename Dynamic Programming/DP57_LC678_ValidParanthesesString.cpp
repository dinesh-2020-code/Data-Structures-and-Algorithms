/**
 * Problem Link: https://leetcode.com/problems/valid-parenthesis-string/description/
 * Problem Statement:
 * Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
 * The following rules define a valid string:
 *      -> Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 *      -> Any right parenthesis ')' must have a corresponding left parenthesis '('.
 *      -> Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 *      -> '*' could be treated as a single right parenthesis ')' or a single left parenthesis
 *          '(' or an empty string "".
 * Example 1:
 * Input: s = "()"      Output: true
 * 
 * Example 2:
 * Input: s = "(*)"     Output: true
 * 
 * Example 3:
 * Input: s = "(*))"    Output: true
 * 
 * Input: s = ")**(*()**"   Output: False
 * 
 * Input: s = "((*)(*))()*(*)****((*(*)())*()((()**(**)"    Output: True
 * Input: s = "(*()(**(*)())*))())())*)()()*(((*)()))(**()*)**(*"       Output: True
 * Input: s = "(((((()*)(*)*))())())(()())())))((**)))))(()())()"       Outupt: False
*/

#include <iostream>
#include <vector>

using namespace std;

bool solve(int ind, int count, string &s, vector<vector<int>> &dp)
{
    // base cases
    // index reaches `n`, check if count == 0, if count is 0 the number of opening and closing brackets are same
    // which makes the given string as valid string.
    //  if count is non-zero, then it's not a valid string return false
    if (ind == s.size())
        return (count == 0);

    if (count < 0)
        return 0;
    if (dp[ind][count] != -1)
        return dp[ind][count];
    if (s[ind] == '(')
    {
        return dp[ind][count] = solve(ind + 1, count + 1, s, dp);
    }
    else if (s[ind] == ')')
    {
        return dp[ind][count] = solve(ind + 1, count - 1, s, dp);
    }
    else
    {
        // s[ind] == '*'
        // case 1: we can treat the '*' as empty string solve(ind + 1, count)
        // case 2: we can treat the '*' as opening bracket '(' i.e., solve(ind + 1, count + 1)
        // case 3: we can treat the '*' as closing bracket ')' i.e., solve(ind + 1, count - 1)
        return dp[ind][count] = solve(ind + 1, count, s, dp)         // case1
                                || solve(ind + 1, count + 1, s, dp)  // case 2
                                || solve(ind + 1, count - 1, s, dp); // case 3
    }
}

bool memo(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(0, 0, s, dp);
}

bool checkValidStringTab(string &s)
{
    // write base cases in the dp table
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    dp[n][0] = true; // base case an empty string with 0 opening brackets is valid

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int count = 0; count <= n; count++)
        {
            if (s[ind] == '(')
            {
                dp[ind][count] = dp[ind + 1][count + 1];
            }
            else if (s[ind] == ')')
            {
                dp[ind][count] = (count > 0) ? dp[ind + 1][count - 1] : 0;
            }
            else
            {
                bool case1 = dp[ind + 1][count];
                bool case2 = dp[ind + 1][count + 1];
                bool case3 = (count > 0) ? dp[ind + 1][count - 1] : 0;
                dp[ind][count] = case1 | case2 | case3;
            }
        }
    }
    return dp[0][0];
}


int main()
{

    string s = "(((((()*)(*)*))())())(()())())))((**)))))(()())()";
    cout << "isValidString: " << memo(s) << endl;
    cout << "isValidString: " << checkValidStringTab(s) << endl;
    return 0;
}