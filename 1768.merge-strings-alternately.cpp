/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=word1.size();
        int l2=word2.size();
        int i=0,j=0;
        string ans;
        while(i<l1 || j<l2){
            if(i<l1)
            ans.push_back(word1[i++]);
            if(j<l2)
            ans.push_back(word2[j++]);
            
        }
    //     if(i==l1)
    //     // ans.append(word2.begin()+j,word2.end());
    //     {while(j<l2)
    //     {ans.push_back(word2[j]);
    //     j++;
    //     }}
    //     else
    //     // ans.append(word1.begin()+i,word1.end());
    // {while(i<l1)
    //     {ans.push_back(word1[i]);
    //     i++;
    //     }}
        return ans;
        
    }
};
// @lc code=end

