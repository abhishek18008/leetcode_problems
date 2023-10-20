/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    typedef pair<int,int> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<P> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        queue<P> q;
        q.push({src, 0}); // Push the source node with distance 0.
        int level = 0;

        while (!q.empty() && level <= k) {
            int N = q.size();
            while (N--) {
                auto x = q.front();
                q.pop();
                int node = x.first;
                int currentDist = x.second;

                for (auto it : adj[node]) {
                    int neighbour = it.first;
                    int cost = it.second;
                    if (currentDist + cost < dist[neighbour]) {
                        dist[neighbour] = currentDist + cost;
                        q.push({neighbour, currentDist + cost});
                    }
                }
            }
            level++;
        }
        
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};

// @lc code=end

