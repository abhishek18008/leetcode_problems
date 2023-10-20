/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> outgoing(n + 1, 0);
    vector<int> incoming(n + 1, 0);

    for (auto it : trust) {
        outgoing[it[0]]++;
        incoming[it[1]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (outgoing[i] == 0 && incoming[i] == n - 1) {
            return i;
        }
    }

    return -1;
}

};
// @lc code=end

