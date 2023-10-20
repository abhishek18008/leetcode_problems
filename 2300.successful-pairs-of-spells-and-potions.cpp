/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
class Solution {
public:
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int spell: spells) {
            long potion_needed = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), potion_needed);
            res.push_back(potions.end() - it);
        }
        return res;
    }

};
// @lc code=end

