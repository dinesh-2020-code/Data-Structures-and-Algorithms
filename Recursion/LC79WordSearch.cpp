/**
 * Problem Link: https://leetcode.com/problems/word-search/description/
 * 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
private:
    bool solve(int i, int j, int k, int m, int n, string word, vector<vector<char>> &board) 
    {
        //base case
        // if k reaches the end of word, => word found
        if (k == word.length())
            return true;
        
        //check for out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        
        //check whether cell is previously visited
        if (board[i][j] == '$')
            return false;

        if (board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int x = 0; x < 4; x++) {
            int _i = i + dx[x];
            int _j = j + dy[x];

            if (solve(_i, _j, k + 1, m, n, word, board)) 
                return true;
        }
        board[i][j] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        //we can start from every possible cell of matrix iff cell value == word[0]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] &&
                    solve(i, j, 0, m, n, word, board))
                    return true;
            }
        }
        return false;
    }
};

int main () {

    Solution obj;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";

    if (obj.exist(board, word)) 
        cout << word << " found in board\n";
    else
        cout << word << " not found in board\n";
    return 0;
}
