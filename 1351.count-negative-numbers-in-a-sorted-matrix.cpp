/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int r=row-1,c=0,count=0;
        while(r>=0 && c<col){
            if(grid[r][c]<0){
                r--;
                count+=col-c;
            }
            else{
                c++;
            }
        }
        return count;
        
        
    }
};
// @lc code=end

