/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

// @lc code=start
class Solution {
public:
    bool solve(int n){
        string str=to_string(n);
        bool shouldbe=false;
        bool shouldnot=true;
        for(auto s:str){
            if(s=='2' || s=='5' || s=='6'|| s=='9'){
                shouldbe=true;
            } 
            if(s=='3' || s=='4' || s=='7'){
                shouldnot=false;
            }
        }
        return shouldbe && shouldnot;
    }
    int rotatedDigits(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+solve(i);
        }
        return dp[n];
        
    }
};
// @lc code=end

