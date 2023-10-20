/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        // int windowmax=INT_MIN;
        // int windowmin=INT_MAX;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(j<n){
            // windowmax=max(windowmax,nums[j]);
            // windowmin=min(windowmin,nums[j]);
            if(j-i+1!=k){
                j++;
            }

            else{
                ans=min(ans,nums[j]-nums[i]);
                i++;
                j++;

            }



        }
        return ans;
        
        
    }
};
// @lc code=end

