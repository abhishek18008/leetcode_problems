/*
 * @lc app=leetcode id=1876 lang=cpp
 *
 * [1876] Substrings of Size Three with Distinct Characters
 */

// @lc code=start
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        int count=0;
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        while(i<n && j<n){
            mp[s[j]]++;
            //if window length is not 3 increase j
            if(j-i+1<3){
                j++;
            }
            else{
                if(mp.size()==3){
                    
                    mp.erase(s[i]);
                    j++;
                    i++;
                    count++;
                    
                }

                else{
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                    j++;
                    
                    
                }
            }
        }
        return count;
        
        
    }
};
// @lc code=end

