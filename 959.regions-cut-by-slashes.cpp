/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
class Solution {
public:
   
    void dfs(vector<vector<int>>& graph,int i,int j,vector<vector<int>>& visited){
        int N=graph.size();
        visited[i][j]=1;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int newx=i+dx[k];
            int newy=j+dy[k];
            if(newx>=0 && newx<N && newy>=0 && newy<N && visited[newx][newy]==-1 && graph[newx][newy]==0){
                dfs(graph,newx,newy,visited);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> graph(3*n,vector<int>(3*n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    graph[3*i][3*j+2]=1;
                    graph[3*i+1][3*j+1]=1;
                    graph[3*i+2][3*j]=1;
                }
                else if(grid[i][j]=='\\'){
                    graph[3*i][3*j]=1;
                    graph[3*i+1][3*j+1]=1;
                    graph[3*i+2][3*j+2]=1;

                }
            }
        }
        
        //count no of islands
        int count=0;
        vector<vector<int>> visited(3*n,vector<int>(3*n,-1));
        for(int  i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(visited[i][j]==-1 && graph[i][j]==0){
                    dfs(graph,i,j,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

