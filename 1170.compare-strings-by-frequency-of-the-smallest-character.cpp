/*
 * @lc app=leetcode id=1170 lang=cpp
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 */

// @lc code=start
class Solution {
public:
    int f(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                return freq[i];
            }
        }
        return 0;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordsans, ans;
        for (string word : words) {
            wordsans.push_back(f(word));
        }
        sort(wordsans.begin(), wordsans.end());

        for (string query : queries) {
            int tofind = f(query);
            int idx = upper_bound(wordsans.begin(), wordsans.end(), tofind) - wordsans.begin();
            ans.push_back(words.size() - idx);
        }
        return ans;
    }
};

// @lc code=end

