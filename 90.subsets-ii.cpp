/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& nums,int idx,vector<int>& temp){
        int n=nums.size();
        if(idx==n) s.insert(temp);
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp);
        temp.pop_back();
        solve(nums,idx+1,temp);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        vector<vector<int>> ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};
// @lc code=end

