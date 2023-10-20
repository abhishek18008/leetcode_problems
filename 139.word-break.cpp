/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    unordered_map<string,bool> mp;

    bool isValid(string& target, int index, string nextword) {
    int length = nextword.size();
    if (target.substr(index, length) == nextword) {
        return true;
    }
    return false;
}

bool solve(string& target, vector<string>& wordList, string& formedtillnow) {
    int targetLength = target.size();
    int currLength = formedtillnow.size();

    // base case
    if (currLength == targetLength) {
        return true;
    }

    if(mp.find(formedtillnow)!=mp.end())
    return mp[formedtillnow];

    for (int i = 0; i < wordList.size(); i++) {
        if (isValid(target, currLength, wordList[i])) {
            formedtillnow += wordList[i];
            if (solve(target, wordList, formedtillnow)) {
                return mp[formedtillnow]=true;
            } else {
                formedtillnow.erase(formedtillnow.size() - wordList[i].size());
            }
        }
    }

    return  mp[formedtillnow]=false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    string formedtillnow = "";
    return solve(s, wordDict, formedtillnow);
}

};
// @lc code=end

