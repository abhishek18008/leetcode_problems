/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
public:
    void dfs(unordered_map<string,vector<pair< string,double>>>& mp,unordered_set<string>& visited,
    string node,string dest,
    double product,double& ans){

        if(visited.find(node)!=visited.end()){
            return;
        }
        visited.insert(node);
         if(node == dest){
            ans = product;
            return;
        }

        for(auto it : mp[node]){

            dfs(mp,visited,it.first,dest,product*it.second,ans);
            
        }
        return ;

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // form the map 
        unordered_map<string,vector<pair< string,double>>> mp;

        int n=equations.size();
        for(int i=0;i<n;i++){
            // a--->(b, 0.40000)
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            // b--->(a, 2.50000)
            mp[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }

        vector<double> ans;

        for(int i=0;i<queries.size();i++){
            unordered_set<string> visited;
            string start=queries[i][0];
            string dest=queries[i][1];
            double prod=-1.0;
            
            if(mp.find(start)!=mp.end()){
                dfs(mp,visited,start,dest,1.0,prod);
            }
            ans.push_back(prod);

        }
        return ans;


    }
};
// @lc code=end

