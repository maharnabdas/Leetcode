// https://leetcode.com/problems/regions-cut-by-slashes/solutions/205674/dfs-on-upscaled-grid/
// https://www.youtube.com/watch?v=zMqgIbLLsc4 ; Video solution to question
// Whenever dealing with symbols, for ex: '/', '\\', ' ' etc. convert them into something computable. In this question that means 3 * 3 matrices.
/*
    / = 0 0 1   \ = 1 0 0   ' ' = 0 0 0
        0 1 0       0 1 0         0 0 0
        1 0 0       0 0 1         0 0 0
*/
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::max;
using std::min;
using std::string;
using std::vector;

class Solution
{
public:
    int dfs(vector<vector<int>> &mat, int i, int j)
    {
        if (min(i, j) < 0 || max(i, j) >= mat.size() || mat[i][j] != 0)
        {
            return 0;
        }
        mat[i][j] = 1;
        return 1 + dfs(mat, i + 1, j) + dfs(mat, i, j - 1) + dfs(mat, i, j + 1) + dfs(mat, i - 1, j);
    }

public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size(), ans = 0;
        vector<vector<int>> mat(n * 3, vector<int>(n * 3));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                switch (grid[i][j])
                {
                case '/':
                {
                    mat[3 * i][3 * j + 2] = 1;
                    mat[3 * i + 1][3 * j + 1] = 1;
                    mat[3 * i + 2][3 * j] = 1;
                    break;
                }
                case '\\':
                {
                    mat[3 * i][3 * j] = 1;
                    mat[3 * i + 1][3 * j + 1] = 1;
                    mat[3 * i + 2][3 * j + 2] = 1;
                }
                }
            }
        }
        for (int i = 0; i < 3 * n; i++)
        {
            for (int j = 0; j < 3 * n; j++)
            {
                ans += dfs(mat, i, j) > 0 ? 1 : 0;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> grid = {"/\\", "\\/"};
    /* -----
       |/|\|
       |\|/|
       -----
    */
    cout << sol.regionsBySlashes(grid) << '\n'; // Output: 5;
}
