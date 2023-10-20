/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(string & s,int idx,bool bbefore){

    //     //base case
    //     if(idx==s.size())
    //     return 0;

    //     if(dp[idx][bbefore]!=-1) return dp[idx][bbefore];

    //     if(s[idx]=='b' && bbefore==true)
    //     return dp[idx][bbefore]=solve(s,idx+1,true);
        
    //     else if(s[idx]=='a' && bbefore==true)
    //     return dp[idx][bbefore]=solve(s,idx+1,true)+1;

    //     else if(s[idx]=='a' && bbefore==false)
    //     return dp[idx][bbefore]=min(solve(s,idx+1,false),solve(s,idx+1,true)+1);
        
    //     // if(s[idx]=='b' && bbefore==false)
    //     else
    //     return dp[idx][bbefore]=min(solve(s,idx+1,true),solve(s,idx+1,false)+1);

    // }
    int minimumDeletions(string s) {
        int n=s.size();
        // dp.resize(n+1,vector<int>(2,-1));
        // if(s[0]=='b')
        // return min(solve(s,0,true),solve(s,1,false)+1);
        // return solve(s,0,false);
        int ans=INT_MAX;
        int counta=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a') counta++;
        
        }
        int countb=0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='a') counta--;     
            ans=min(ans,counta+countb);    
            if(s[i]=='b') 
             countb++;
            
        }

        
        return ans==INT_MAX ? 0 : ans;
        
    }
};
// @lc code=end

