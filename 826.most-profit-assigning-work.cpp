/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution {
public:
   
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());

        int ans=0;
        int i=0;
        int maxi=0;
        for(auto it:worker){
            while(i<n  && it>=v[i].first){
                maxi=max(maxi,v[i].second);
                i++;
            }
            ans+=maxi;

        }
        return ans;
        
    }
};
// @lc code=end

