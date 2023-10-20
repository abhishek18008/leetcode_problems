/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class setunion{
    public:
    vector<int> rank;
    vector<int> parent;
    setunion(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return;
        if(rank[pa]>rank[pb]) 
        parent[pb]=pa;
        else if(rank[pb]>rank[pa])
        parent[pa]=pb;
         else{
            parent[pa]=pb;
            rank[pb]++;
         }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // make an object of set
        setunion ds(26);
        for(auto it : equations){
            if(it[1]=='=')
            ds.Union(it[0]-'a',it[3]-'a');
        }


        for(auto it: equations){
            if(it[1]=='!'){
                if(ds.find(it[0]-'a')==ds.find(it[3]-'a')){
                    return false;
                }
            }
        }
        return true;
        
    }
};
// @lc code=end

