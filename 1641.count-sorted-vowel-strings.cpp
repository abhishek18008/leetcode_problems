/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 */

// @lc code=start
class Solution {
public:
    int countVowelStrings(int n) {
        int ans = 0;
        for (int j=1; j<=(n+1); j++) {
            int sum = 0;
            for (int i=1; i<=j; i++) {
                sum += i;
                ans += sum;
            }
        }
        return ans;
    }
};
// @lc code=end

