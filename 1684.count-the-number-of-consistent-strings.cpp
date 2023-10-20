/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
    int ans=words.size();
    vector<bool> present(26,0);
    for(auto it: allowed){
        present[it-'a']=1;
    }

    for(auto it: words){
        for(char c: it){
            if(!present[c-'a']){
                ans--;
                break;
            }
        }
    }
    
    
    
    return ans;
}

};
// @lc code=end

