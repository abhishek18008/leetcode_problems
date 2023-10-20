/*
 * @lc app=leetcode id=2305 lang=cpp
 *
 * [2305] Fair Distribution of Cookies
 */

// @lc code=start
class Solution {
public:
    int n;
    int ans=INT_MAX;
    void solve(vector<int>& cookies,int idx,vector<int>& dist){
        //base case
        if(idx==n){
             ans=min(ans,*max_element(begin(dist),end(dist)));
            return;
        }
        //give this to one of k children
        for(int i=0;i<dist.size();i++){
            dist[i]+=cookies[idx];
            solve(cookies,idx+1,dist);
            dist[i]-=cookies[idx];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        //initially everyone has k cookies
        vector<int> dist(k,0);
        solve(cookies,0,dist);
        return ans;
    
    }
};
// @lc code=end

