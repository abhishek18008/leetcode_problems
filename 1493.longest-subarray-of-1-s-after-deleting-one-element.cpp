/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int numzeros=0;
        int i=0,j=0;
        int maxlen=0;
        while(j<n){
            if(nums[j]==0){
                numzeros++;
            }
            if(numzeros>1){
                while(numzeros!=1){
                    if(nums[i]==0) numzeros--;
                    i++;
                }
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen-1;
  
}

};
// @lc code=end

