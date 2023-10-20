/*
 * @lc app=leetcode id=669 lang=cpp
 *
 * [669] Trim a Binary Search Tree
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

    TreeNode* solve(TreeNode* root, int low,int high){
        if(!root) return nullptr;

        if(root->val <low){
            return solve(root->right,low,high);
        }

        if(root->val >high){
            return solve(root->left,low ,high);
        }

        root->left=solve(root->left,low,high);
        root->right=solve(root->right,low,high);
        return root;


    }


    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
        
    }
};
// @lc code=end

