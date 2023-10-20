/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

// @lc code=start
class Solution {
public:
    void bfs(vector<int>& edges,vector<int>& dist1,int source){
        dist1[source]=0;
        queue<int> q;
        int n=edges.size();
        vector<int> visited(n,0);
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(edges[node]!=-1 && !visited[edges[node]]){
            dist1[edges[node]]=dist1[node]+1;
            visited[edges[node]]=1;
            q.push(edges[node]);
            }

        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        bfs(edges,dist1,node1);
        bfs(edges,dist2,node2);

        int smallestindex=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                if(max(dist1[i],dist2[i]) < mini){
                    mini=max(dist1[i],dist2[i]);
                    smallestindex=i;
                }
            }
        }
        return smallestindex;
        

        
    }
};
// @lc code=end

