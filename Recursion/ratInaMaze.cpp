/**
 * Backtracking Problem
 * Problem Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
 * 
 * Problem Statement:
 * Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1).
 * Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can
 * move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and
 * rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
 * Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.
 * 
 *  N = 4
 *  m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
         
    Output: DDRDRR DRDDRR
*/

#include <iostream>
#include <vector>

using namespace std;

void solve(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &vis, string move) {
    //base case
    if (i == n - 1 && j == n - 1)
    {
        //print move
        cout << move << "\n";
        return;
    }
    //downward move
    if (i + 1 < n && !vis[i + 1][j] && mat[i + 1][j] == 1) {
        vis[i][j] = 1;
        solve(i + 1, j, n, mat, vis, move + 'D');
        vis[i][j] = 0;
    }

    //left move
    if (j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1] == 1) {
        vis[i][j] = 1;
        solve(i , j - 1, n, mat, vis, move + 'L');
        vis[i][j] = 0;
    }

    //right move
    if (j + 1 < n && !vis[i][j + 1] && mat[i][j + 1] == 1) {
        vis[i][j] = 1;
        solve(i, j + 1, n, mat, vis, move + 'R');
        vis[i][j] = 0;
    }

    //upward move
    if (i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j] == 1) {
        vis[i][j] = 1;
        solve(i - 1, j, n, mat, vis, move + 'U');
        vis[i][j] = 0;
    }
}


void solve2(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &vis, string move, int di[], int dj[]) {
    //base case
    if (i == n - 1 && j == n - 1)
    {
        //print move
        cout << move << "\n";
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && mat[nexti][nextj]) {
            vis[i][j] = 1;
            solve2(nexti, nextj, n, mat, vis, move + dir[ind], di, dj);
            vis[i][j] = 0;
        }
    }
}

int main() 
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    int n = mat.size();
    vector<vector<int>> vis(n, vector<int> (n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, +1, 0};
    if (mat[0][0] == 1) {
        // solve(0, 0, n, mat, vis, "");
        solve2(0, 0, n, mat, vis, "", di, dj);
    }

    return 0;


}
/*
    Time Complexity: 4 ^ n * n
    Aux space: O(n * n)
*/