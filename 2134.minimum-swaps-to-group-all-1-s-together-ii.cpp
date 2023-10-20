/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //count total no of o's and total size
        // find a window of len n-k with max no of zeros in this
        
        int ws=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();

        int sum=0;
        int maxi=INT_MIN;
        int i=0,j=0;
        while(j<n+ws){
            sum+=nums[j%n];
            if(j-i+1>ws){
                sum-=nums[i%n];
                i++;
            }
            maxi=max(maxi,sum);
            j++;
        }
        return ws-maxi;
        
    }
};
// @lc code=end

