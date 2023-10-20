/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
public:
    typedef pair<int,int> P;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
     vector<vector<int>>& blueEdges) {
        vector<vector<P>> edges(n);
        for(auto it: redEdges){
            //x---{y , -1}
            int x=it[0];
            int y=it[1];
            edges[x].push_back({y,-1});
        }
        for(auto it:blueEdges ){
            int x=it[0];
            int y=it[1];
            edges[x].push_back({y,1});
        }
        vector<int> ans(n,-1);
        ans[0]=0;
        queue<P> q;
        vector<int> visited(n,0);
        visited[0]=1;
        for(auto it: edges[0]){
            //dist will be 1 for all 
            //colour will be it[1];
            ans[it.first]=1;
            q.push({it.first,it.second});
            visited[it.first]=1;
        }
        
        int dist=0;
        while(!q.empty()){
            //process all the nodes currently in queue at once
            int sz=q.size();
            int dist=2;
            while(sz--){
                auto x=q.front();
                q.pop();
                for(auto it: edges[x.first]){
                    int adj_node=it.first;
                    int adj_colour=it.second;
                    if(!visited[adj_node] && adj_colour == -x.second){
                        ans[adj_node]=dist;
                        q.push({adj_node,adj_colour});
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};
// @lc code=end

