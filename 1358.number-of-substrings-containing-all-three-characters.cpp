/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0,j=0;
        unordered_map<char,int> mp;
        int ans=0;
        while(j<n){
            mp[s[j]]++;

            //if this window is valid
            while(mp['a']  && mp['b'] && mp['c']){
                ans+=n-j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
        
    }
};
// @lc code=end

