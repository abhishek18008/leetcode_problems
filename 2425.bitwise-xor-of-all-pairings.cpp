/*
 * @lc app=leetcode id=2425 lang=cpp
 *
 * [2425] Bitwise XOR of All Pairings
 */

// @lc code=start
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        //only consider xor of array with even total number of elements
        int ans=0;
        if(n&1){
            for(auto it:nums2)
            ans^=it;
        }
        if(m&1){
            for(auto it:nums1)
            ans^=it;
        }
        return ans;
    }
};
// @lc code=end

