/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
public:
    int res=0;
void solve(vector<vector<int>>& grid, int x, int y, int count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return;
        
        if (grid[x][y] == 2) {
            if(count == 0) res++; 
            return;
        }
        
        grid[x][y] = -1;
        
        solve(grid, x+1, y, count-1);
        solve(grid, x-1, y, count-1);
        solve(grid, x, y+1, count-1);
        solve(grid, x, y-1, count-1);
        
        grid[x][y] = 0;
        
    }

int uniquePathsIII(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int xs, ys, xe, ye;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int count=1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                xs = i;
                ys = j;
            } else if (grid[i][j] == 2) {
                xe = i;
                ye = j;
            }
            else if(grid[i][j]==0)
            count++;
        }
    }
    solve(grid, xs, ys,count);
    return res;
    
    
}

};
// @lc code=end

