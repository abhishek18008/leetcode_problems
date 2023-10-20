/*
 * @lc app=leetcode id=2385 lang=cpp
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void createGraph(TreeNode* root,vector<int>* adj){
        if(root==NULL){
            return;
        }

        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);

        }
        
        createGraph(root->left,adj);
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        
        createGraph(root->right,adj);
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<int> adj[100001];
        createGraph(root,adj);
       
        vector<int> visted(100001,0);
        int time=0;
        queue<int> q;
        q.push(start);
        visted[start]=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int x=q.front();
              q.pop();
                for(auto it : adj[x]){
                if(visted[it]==0)
                {
                    q.push(it);
                    visted[it]=1;
                }
            }
            
            }
            time++;
        }
    return time-1;
        
    }
};
// @lc code=end

