/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //map to store index of each chars of s
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }

        //check if word in words is a subsequence
        int ans=0;
        for(auto word: words){
            bool found=true;
            int prev=-1;
            for(auto it:word){
                auto x=upper_bound(mp[it].begin(),mp[it].end(),prev);
                if(x==mp[it].end())// such idx doesn't exist
                found=false;
                else 
                prev=*x;
            }
            ans+=found;
        }
        return ans;
    }
};
// @lc code=end

