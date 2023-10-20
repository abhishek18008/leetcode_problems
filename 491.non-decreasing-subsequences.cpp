/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
class Solution {
public:
    // set<vector<int>> ans;
    // void solve(vector<int>nums,int prev,int idx,vector<int>& temp){
    //     int n=nums.size();
    //     if(idx==n){
    //         if(temp.size()>=2){
    //             ans.insert(temp);
    //         }
    //         return;
    //     }
    //     //choose this if greater or equal to prev
    //     if(nums[idx]>=prev){
    //         temp.push_back(nums[idx]);
    //         solve(nums,nums[idx],idx+1,temp);
    //         temp.pop_back();
    //     }

    //     solve(nums,prev,idx+1,temp);
    // }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //using backtracking
        // vector<int> temp;
        // solve(nums,-101,0,temp);
        // vector<vector<int>> a;
        // for(auto it:ans){
        //     a.push_back(it);
        // }
        // return a;

        //using bitmask
        




    }
};
// @lc code=end

