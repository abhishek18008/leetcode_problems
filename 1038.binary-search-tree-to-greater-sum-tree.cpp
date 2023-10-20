/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
    void change(TreeNode* root,int& count){
        if(!root) return ;
        
        change(root->right,count);
        root->val+=count;
        count=root->val;
        change(root->left,count);
        

    }


    TreeNode* bstToGst(TreeNode* root) {
        int count=0;
        change(root,count);
        return root;
        
    }
};
// @lc code=end

