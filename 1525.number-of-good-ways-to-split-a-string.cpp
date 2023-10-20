/*
 * @lc app=leetcode id=1525 lang=cpp
 *
 * [1525] Number of Good Ways to Split a String
 */

// @lc code=start
class Solution {
public:
    int numSplits(string s) {
    unordered_map<char, bool> fromleft;
    unordered_map<char, bool> fromright;
    int leftcount = 0;
    vector<int> leftdist(s.size());
    vector<int> rightdist(s.size());

    for (int i = 0; i < s.size(); i++) {
        if (fromleft.find(s[i]) == fromleft.end()) {
            fromleft[s[i]] = true;
            leftcount++;
        }
        leftdist[i] = leftcount; // Assign leftcount to the leftdist[i] element
    }

    int rightcount = 0;
    for (int i = s.size() - 1; i >= 0; i--) { // Corrected the loop condition
        if (fromright.find(s[i]) == fromright.end()) {
            fromright[s[i]] = true;
            rightcount++;
        }
        rightdist[i] = rightcount; // Assign rightcount to the rightdist[i] element
    }

    int ans = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (leftdist[i] == rightdist[i + 1])
            ans++;
    }

    return ans;
}

};
// @lc code=end

