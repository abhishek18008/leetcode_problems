/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
    int findmindays(vector<int> & weights,int cap){
        int n=weights.size();
        int sum=0;
        int days=1;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum>cap){
                days++;
                sum=weights[i];
            }
        }
        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxi=*max_element(weights.begin(),weights.end());
        int sum=accumulate(weights.begin(),weights.end(),0);
        for(int cap=maxi,cap<=sum;i++){
            if(findmindays(weights,cap)<=days)
            return cap;
        }

        
    }
};
// @lc code=end

