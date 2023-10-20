/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        
        set<vector<int>> st;

        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=nums[i]+nums[j];
                if(mp.count(-sum) && mp.find(-sum)->second>j){
                    vector<int> temp={nums[i],nums[j],-sum};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    
                }
               
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
        
    }
};
// @lc code=end

