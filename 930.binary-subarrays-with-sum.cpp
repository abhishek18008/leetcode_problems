/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution {
public: 
    int atmost(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int n=nums.size();
        int i=0,j=0;
        int sum=0;
        int ans=0;
        while(j<n){
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }



    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};
// @lc code=end

