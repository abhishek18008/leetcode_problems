/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int idx,vector<int>& temp){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }
        

        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp);
        temp.pop_back();
        solve(nums,idx+1,temp);


    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        //use bitmasking
        // vector<vector<int>> ans;
        // for(int i=0;i<(1<<n);i++){
        //     vector<int> temp;
        //     for(int j=0;j<n;j++){
        //         //check if jth bit is set
        //         if((i&(1<<j))!=0){
        //             temp.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        vector<int> temp;
        //using backtracking
        solve(nums,0,temp);
        return ans;

        
    }
};
// @lc code=end

