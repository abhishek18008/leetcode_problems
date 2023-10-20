/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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

    void solve(TreeNode* root,int &count){
        if(!root) return ;
        solve(root->right,count);
        count+=root->val;
        root->val=count;
        solve(root->left,count);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        int count=0;
        solve(root,count);
        return root;
        
    }
};
// @lc code=end

