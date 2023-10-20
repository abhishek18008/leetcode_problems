/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start
class Solution {
public:
   vector<int> rearrangeArray(vector<int>& nums) {
    int n=nums.size();
        vector<int> ans(n,0);
        int indexpos = 0, indexneg=1;
        for(auto num: nums){
            if(num>0){
                ans[indexpos] = num;
                indexpos+=2;
            }
            if(num<0){
                ans[indexneg] = num;
                indexneg += 2;
            }
        }
        return ans;
        
    }
};
// @lc code=end

