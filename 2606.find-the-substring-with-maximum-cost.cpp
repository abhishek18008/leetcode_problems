/*
 * @lc app=leetcode id=2606 lang=cpp
 *
 * [2606] Find the Substring With Maximum Cost
 */

// @lc code=start
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int> mp;
        for(char it='a';it<='z';it++){
            mp[it]=it-'a'+1;
        }
        for(int i=0;i<chars.size();i++){
            mp[chars[i]]=vals[i];
        }        
        
        // int i=0,j=0;
        // int n=s.size();
        // while(j<n){
        //     sum+=mp[s[j]];
        //     //if sum gets negative move the i until it is again positive
        //     while(sum<0){
        //         sum-=mp[s[i]];
        //         i++;
        //     }
        //     maxi=max(maxi,sum);
        //     j++;

        // }

        int currsum=0;
        int maxsum=INT_MIN; 
        int n=s.size();
        for(int i=0;i<n;i++){
            currsum+=mp[s[i]];
            if(currsum<0)
            currsum=0;
            maxsum=max(maxsum,currsum);
        }


        return maxsum;

    }
};
// @lc code=end

