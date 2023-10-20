/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n);
        // Assume only left dominoes are falling from the right side
        int dist = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == '.' && dist != INT_MAX) {
                dist++;
            }
            if (dominoes[i] == 'L') {
                dist = 0;
            }
            if (dominoes[i] == 'R') {
                dist = INT_MAX;
            }
            left[i] = dist;
        }
        
        // Assume only right dominos are falling from the left side
        vector<int> right(n);
        dist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.' && dist != INT_MAX) {
                dist++;
            }
            if (dominoes[i] == 'R') {
                dist = 0;
            }
            if (dominoes[i] == 'L') {
                dist = INT_MAX;
            }
            right[i] = dist; // Fix here: update the right vector
        }

        string ans;
        ans.resize(n);
        for (int i = 0; i < n; i++) {
            if (left[i] < right[i]) {
                ans[i] = 'L';
            } else if (right[i] < left[i]) {
                ans[i] = 'R';
            } else {
                ans[i] = '.';
            }
        }
        return ans;
    }
};

// @lc code=end

