/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //use kahn's algo
        vector<int> incoming(numCourses,0);
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            incoming[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(incoming[i]==0)
            q.push(i);
        }

        stack<int> st;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            st.push(node);
            for(auto it: adj[node]){
                if(incoming[it]>0)
                incoming[it]--;
                if(incoming[it]==0){
                    q.push(it);
                }
            }
        }
        for(auto it: incoming){
            if(it!=0)
            return false;
        }
        return true;
        
        
    }
};
// @lc code=end

