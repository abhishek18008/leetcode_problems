/*
 * @lc app=leetcode id=1387 lang=cpp
 *
 * [1387] Sort Integers by The Power Value
 */

// @lc code=start
class Solution {
public:
    int solve(int n,unordered_map<int,int>& m){
        if(n==1) return 0;
        if(m[n]) return m[n];
        
            if(n%2==0){
                m[n]= solve(n/2,m)+1;
            }
            
            else{
                m[n]= solve(3*n+1,m)+1;
            }
        
        return m[n];
    }
    
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int> m;
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;i++){
            v.push_back({solve(i,m),i});
        }
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};
// @lc code=end

