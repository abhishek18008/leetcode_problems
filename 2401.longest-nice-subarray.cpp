/*
 * @lc app=leetcode id=2401 lang=cpp
 *
 * [2401] Longest Nice Subarray
 */

// @lc code=start
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maximum_length = 1;
        int n = nums.size();
        
        int current_group = 0;
        int i = 0; // equivalent to left
        int j = 0; // equivalent to right
        
        while (j < n) {
            // If the number at the right pointer is safe to include, include it in the group and update the maximum length.
            if ((nums[j] & current_group) == 0) {
                current_group |= nums[j];
                maximum_length = max(maximum_length, j - i + 1);
                j++;
                continue;
            }
            
            // Shrink the window until the number at the right pointer is safe to include.
            while (i < j && (nums[j] & current_group) != 0) {
                current_group &= (~nums[i]);
                i++;
            }
            
            // Include the number at the right pointer in the group.
            current_group |= nums[j];
            j++;
        }
        
        return maximum_length;
    }
};

// @lc code=end

