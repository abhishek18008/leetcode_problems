/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int vowelcount=0,i=0,j=0;
        int maxi=0;
        while(j<n){
            if(s[j]=='a' ||s[j]=='e' || s[j]=='i'|| s[j]=='o'|| s[j]=='u'){
                vowelcount++;
            }
            if(j-i+1>k){
                if(s[i]=='a' ||s[i]=='e' || s[i]=='i'|| s[i]=='o'|| s[i]=='u')
                vowelcount--;
                i++;
            }
            maxi=max(maxi,vowelcount);
            j++;
        }
        return maxi;
        
    }
};
// @lc code=end

