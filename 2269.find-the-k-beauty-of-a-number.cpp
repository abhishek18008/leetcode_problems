/*
 * @lc app=leetcode id=2269 lang=cpp
 *
 * [2269] Find the K-Beauty of a Number
 */

// @lc code=start
class Solution {
public:
    int divisorSubstrings(int num, int k) {
      int count =0;
        string s=to_string(num);
        int n=s.size();
        int i=0;
        int j=0;
        while(i<n && j<n){
            if(j-i+1!=k){
                j++;
            }
            else{
                int tocheck=stoi(s.substr(i,j-i+1));
                if(tocheck!=0){
                        if(num% tocheck==0){
                     count++;
                }
                }
                
                i++;
                j++;
            }
        }
        return count;
        
    }
};
// @lc code=end

