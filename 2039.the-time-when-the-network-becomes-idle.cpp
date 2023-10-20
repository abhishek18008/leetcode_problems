/*
 * @lc app=leetcode id=2039 lang=cpp
 *
 * [2039] The Time When the Network Becomes Idle
 */

// @lc code=start
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        //find the shortest distance from node 0 for all nodes
        vector<int> time(n,-1);
        vector<int> adj[n];
        for(auto it : edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        queue<int> q;
        time[0]=0;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for( auto it: adj[node]){
                if(time[it]==-1){
                    time[it]=time[node]+1;
                    q.push(it);
                }
            }
        }
        int res=0;
        for(int i = 1; i<n; i++) 
		{
             int d = time[i];
             int temp = 2*d;
             if(2*d > patience[i])
			 {
                if((2*d)%patience[i]==0)
                temp=4*d-patience[i];
                else
                    temp=4*d-(2*d)%patience[i];   
            }
            
            res = max(res,temp);
			
        }
        return res+1;


    }
};
// @lc code=end

