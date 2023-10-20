/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
    int N;
    vector<vector<int>> dp;
    int solve(int clipboard,int req){
        if(req==0) return 0;
        
        if(req<0) return 1e7;
        if(dp[clipboard][req]!=-1) return dp[clipboard][req];
        //just paste the copyboard
        int p=1+solve(clipboard,req-clipboard);
        //paste the copyboard then do a copy
        int newcopyboard=clipboard+N-req;
        int pc= 2+solve(newcopyboard,req-clipboard);
        return dp[clipboard][req]=min(p,pc);
    }


    int minSteps(int n) {
        if(n==1) return 0;
        N=n;
        dp.resize(n+1,vector<int>(n+1,-1));
       
        //copy all will be required
        return 1+solve(1,n-1);
        
    }
};
// @lc code=end

