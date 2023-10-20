/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        int j=1;
        while(j<=n){
            if(s[j]==' ' || j==n){
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
                j=i+1;
            }
            else{
                j++;

            }
        }
        return s;
    }
};
// @lc code=end

