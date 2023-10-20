/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n<2)
        {
            return 1;
        }
        
        
        int x=1;
        int y=2;
        for(int i = 3; i <= n; i++)
        {
            int z=x+y;
            x=y;
            y=z;
        }
        return y;

        
        
    }
};
// @lc code=end

