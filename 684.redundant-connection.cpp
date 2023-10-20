/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start

class UnionFind{
    public:
    vector<int> rank;
    vector<int> parent;

    UnionFind(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }

    int find(int v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }

    void union_set(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return;
    
    if (rank[pa] > rank[pb])
        parent[pb] = pa;
    else if (rank[pa] < rank[pb])
        parent[pa] = pb;
    else {
        parent[pa] = pb;  // Connect pa under pb
        rank[pb]++;       // Increment rank of pb
    }
}


};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        UnionFind ds(n);
        for(auto it: edges){
            int x=it[0];
            int y=it[1];
            int a=ds.find(x);
            int b=ds.find(y);
            if(a==b)
            return {x,y};
            else{
                ds.union_set(a,b);
            }

        }
        return {};
        
    }
};
// @lc code=end

