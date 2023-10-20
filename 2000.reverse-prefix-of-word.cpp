/*
 * @lc app=leetcode id=2000 lang=cpp
 *
 * [2000] Reverse Prefix of Word
 */

// @lc code=start
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        int n=word.size();
        while(word[i]!=ch && i<n)
        i++;
        if(i<word.size())
        reverse(word.begin(),word.begin()+i+1);
        return word;
        
    }
};
// @lc code=end

