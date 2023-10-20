/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads
 */

// @lc code=start
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        for(auto road : roads){
            indegree[road[0]]++;
            indegree[road[1]]++;
        }

        sort(indegree.begin(),indegree.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(long long)indegree[i]*(i+1);
        }
        return ans;


        
    }
};
// @lc code=end

