/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public: 
    //function to find out the max length
    //if we try to make substring of char c;

    // int givelen(string& s, char c,int k){
    //     int n=s.size();
    //     int maxi=0;
    //     int i=0,j=0;
    //     int numdiff=0;
    //     while(j<n){
    //         if(s[j]!=c){
    //             numdiff++;
    //         }
    //         while(numdiff>k){
    //             if(s[i]!=c){
    //                 numdiff--;
    //             }
    //             i++;
    //         }
    //         maxi=max(maxi,j-i+1);
    //         j++;
    //     }
    //     return maxi;
    // }

    int characterReplacement(string s, int k) {
        // int ans=0;
        // vector<int> freq(26,0);
        // for(int i=0;i<)
        // return ans;
         int n = s.size();
        int i = 0, j = 0, maxi = 0;
        unordered_map<char,int>mp;
        int ans = -1;
        while(j < n)
        {
            mp[s[j]]++;
            maxi = max(maxi, mp[s[j]]);
            if((j-i+1) - maxi > k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, (j-i+1));
            j++;   
        }
        return ans;
        
    }
};
// @lc code=end

