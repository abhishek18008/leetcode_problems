/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0;
        int k=0;
        for(int i=n;i>0;++i){
            int j=i;
            while(j>0){
                ans+=(j&1)*(1<<k);
                j=j/2;
                k++;
            }
        }
        return ans;
        
    }
};
// @lc code=end

