/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        double maxavg=-1e5;
        int i=0;
        int j=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1!=k){
                j++;
            }
            else{
                maxavg=max(maxavg,sum/k);
                sum-=nums[i];
                i++;
                j++;
            }

        }
        return maxavg;
        
    }
};
// @lc code=end

