/*
 * @lc app=leetcode id=2089 lang=cpp
 *
 * [2089] Find Target Indices After Sorting Array
 */

// @lc code=start
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller=0,larger=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target)
            smaller++;
            else if(nums[i]>target)
            larger++;
        }
        // [smaller, n-greater-1]
        vector<int> ans;
        for(int i=smaller;i<=n-larger-1;i++){
            if(0<=i && i<n)
            ans.push_back(i);
        }
        return ans;

        
    }
};
// @lc code=end

