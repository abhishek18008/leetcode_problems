/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
    int minidiff = INT_MAX;
    
    void dfs(TreeNode* root, int& prev) {
        if (!root) return;
        
        dfs(root->left, prev);
        
        if (prev != -1) {
            minidiff = min(minidiff, root->val - prev);
        }
        
        prev = root->val;
        
        dfs(root->right, prev);
    }
    
    int minDiffInBST(TreeNode* root) {
        int prev = -1; // Initialize prev to a value that won't appear in the tree
        dfs(root, prev);
        return minidiff;
    }
};

// @lc code=end

