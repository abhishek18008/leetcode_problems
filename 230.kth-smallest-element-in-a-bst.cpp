/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    // int ans;
    // void dfs(TreeNode* root,int & k){
    //     if(!root) return;
    //     dfs(root->left,k);
    //     k--;
    //     if(k==0){
    //         ans=root->val;
    //         return;
    //     }
        
    //     dfs(root->right,k);
        
    // }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(true){
            while(!root){
                stk.push(root->val);
                root=root->left;
            }

            stk.pop();
            k--;
            if(k==0) return stk.top();
            stk.push(root->right);
        }
        
    }
};
// @lc code=end

