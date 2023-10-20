/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(2);
        unordered_set<int> s;
        for(auto it:nums){
            if(s.count(it))
            ans[0]=it;
            s.insert(it);
        }
        for(int i=1;i<=n;i++){
            if(!s.count(i))
            ans[1]=i;
        }
        return ans;
    }
};
// @lc code=end

