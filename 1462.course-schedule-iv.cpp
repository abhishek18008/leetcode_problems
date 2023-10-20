/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses);
        vector<vector<int>> reachable(numCourses,vector<int>(numCourses,0));
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
            reachable[it[0]][it[1]]=1;
        }

        // vector<int> visited(numCourses,0);
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
            {
                q.push(i);
                // visited[i]=true;
            }
        }

        stack<int> st;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            st.push(node);
            for(auto it: adj[node]){
                for(int i=0;i<numCourses;i++){
                    if(reachable[i][node]==1)
                    reachable[i][it]=1;
                }
               
                    if(indegree[it]>0)
                    indegree[it]--;
                    if(indegree[it]==0)
                    q.push(it);
                
            }
        }

        vector<bool> ans;
        for(auto query : queries){
            if(reachable[query[0]][query[1]]==1)
            ans.push_back(true);
            else 
            ans.push_back(false);
        }

       return ans;



    }
};
// @lc code=end

