/*
 * @lc app=leetcode id=2063 lang=cpp
 *
 * [2063] Vowels of All Substrings
 */

// @lc code=start
class Solution {
public:
    long long countVowels(string word) {
        long long ans=0;
        int n=word.size();
        for(int i=0;i<word.size();i++){
            if(word[i]=='a' ||word[i]=='e' ||word[i]=='i' 
            ||word[i]=='o' ||word[i]=='u' ){
                ans+=(long long)(i+1)*(n-i);
            }
        }
        return ans;
    }
};
// @lc code=end

