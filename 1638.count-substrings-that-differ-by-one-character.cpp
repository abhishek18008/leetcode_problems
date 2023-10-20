/*
 * @lc app=leetcode id=1638 lang=cpp
 *
 * [1638] Count Substrings That Differ by One Character
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s, string t) {
    int ans = 0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
        int sindex=i;
        int tindex=j;
        int diff=0;
        while(sindex<s.size() && tindex<t.size()){
            if(s[sindex]!=t[tindex]){
                diff++;
            }
            if(diff==1){
                ans++;
            }
            sindex++;
            tindex++;
            if(diff>1){
                break;
            }

        }
        }
    }
    return ans;
}

};
// @lc code=end

