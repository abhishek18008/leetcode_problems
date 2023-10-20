/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //just brute force
        vector<int> prefixXor;
        int x = 0;
        for (auto it : arr) {
            x ^= it;
            prefixXor.push_back(x);
        }
        vector<int> ans;
        for (auto it : queries) {
            int l = it[0];
            int r = it[1];
            //find xor of [l ,r]
            if (l == 0)
                ans.push_back(prefixXor[r]);
            else
                ans.push_back(prefixXor[r] ^ prefixXor[l - 1]);
        }
        //handle case when l=0;
        return ans;
    }
};
// @lc code=end

// @lc code=end

