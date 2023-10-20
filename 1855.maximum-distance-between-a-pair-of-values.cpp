/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        int ans=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans=max(ans,j-i);
                j++;
            }
            else{
                i++;
            }

        }
        return ans;
    }
};
// @lc code=end

