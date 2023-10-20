/*
 * @lc app=leetcode id=2500 lang=cpp
 *
 * [2500] Delete Greatest Value in Each Row
 */

// @lc code=start
class Solution {
public:
int deleteGreatestValue(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    for (int i = 0; i < m; i++) {
        sort(grid[i].begin(), grid[i].end(), greater<int>()); // Sort in descending order
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int maxElement = 0;
        for (int j = 0; j < m; j++) {
            maxElement=max(maxElement,grid[j][i]);
        }
        ans += maxElement; // Add the greatest element to the answer
    }
    
    return ans;
}

};
// @lc code=end

