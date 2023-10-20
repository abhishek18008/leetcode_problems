/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
public:

    int sum(vector<int>& nums,int divisor){
        int res=0;
        for(auto it: nums){
            res+=ceil((double)it/divisor);
        }
        return res;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1,r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(sum(nums,mid)>threshold){
                l=mid+1;
            }
            else{
                r=mid;
            } 
        }
        return l;
    }
};
// @lc code=end

