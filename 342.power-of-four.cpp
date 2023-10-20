/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int n) {
        bool ans=false;
        for(int i=0;i<31;i+=2){
            if(n==(1<<i))
            ans=true;
        }
        return ans;
    }
};
// @lc code=end

