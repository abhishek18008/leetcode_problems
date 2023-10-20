/*
 * @lc app=leetcode id=1749 lang=cpp
 *
 * [1749] Maximum Absolute Sum of Any Subarray
 */

// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int maxi=INT_MIN;
        int maxsum=0;
        int minsum=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            maxsum +=nums[i];
            minsum += nums[i];
            maxi=max(maxi,maxsum);
            mini=min(mini,minsum);
            if(maxsum<0)
            maxsum=0;
            if(minsum>0)
            minsum=0;
            ans=max(ans,max(maxsum,abs(minsum)));

        }
        return ans;
        
    }
};
// @lc code=end

