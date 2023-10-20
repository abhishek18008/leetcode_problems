/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<int>& visited,int node){
        visited[node]=1;
        for(auto it: rooms[node]){
            if(!visited[it])
            dfs(rooms,visited,it);
        }
    }



    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> visited(n,0);
        dfs(rooms,visited,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0)
            return false;
        }
return true;
    }
};
// @lc code=end

