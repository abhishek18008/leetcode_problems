/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
public:
    unordered_map<string,double> mp;
    double solve(int n,int k ,int r,int c){
        if(r<0 || r>=n || c<0 || c>=n) return 0.0;
        if(k==0){
            return 1.0;
        }

        string key=to_string(k)+"_"+to_string(r)+"_"+to_string(c);
        if(mp.count(key)){
            return mp[key];
        }
        
        int dx[8]={1,2,2,1,-1,-2,-2,-1};
        int dy[8]={2,1,-1,-2,2,1,-1,-2};
        double ans=0.0;
        for(int i=0;i<8;i++){
            int newr=r+dx[i];
            int newc=c+dy[i];
            ans+=solve(n,k-1,newr,newc);
        }
        return mp[key]=ans/8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        return solve(n,k,row,column);
        
    }
};
// @lc code=end

