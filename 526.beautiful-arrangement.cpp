/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution {
public:
    void solve(vector<int>& used,int & count,int idx){
        int n=used.size()-1;
        if(idx==n+1)
        count++;
        for(int i=1;i<=n;i++){
            //check if keeping the i at idx is valid
            if(used[i]==0 && (i%idx==0 || idx%i==0)){
                used[i]=1;
                solve(used,count,idx+1);
                used[i]=0;
            }
        }
    }

    int countArrangement(int n) {
        //to track the used ones
        vector<int> used(n+1,0);
        int count=0;
        solve(used,count,1);
        return count;

        
    }
};
// @lc code=end

