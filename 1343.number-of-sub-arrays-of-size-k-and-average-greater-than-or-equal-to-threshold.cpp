/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 */

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int ans=0;
        int sum=0;
       int i=0,j=0;
       while(j<n){
        sum+=arr[j];
        if(j-i+1==k){
            int avg=sum/k;
            if(avg>=threshold) ans++;
            sum-=arr[i];
            i++;
        }
        j++;
       }
       return ans;
    }
};
// @lc code=end

