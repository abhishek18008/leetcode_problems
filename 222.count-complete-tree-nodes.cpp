/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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




    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        TreeNode* temp=root;
        int lh=0;
        while(temp!=nullptr){
            temp=temp->left;
            lh++;
        }

        int rh=0;
        temp=root;
        while(temp!=nullptr){
            temp=temp->right;
            rh++;
        }

        //if both are samme
        if(lh==rh){
            return (1<<lh)-1;
        }
        else{
            return countNodes(root->left)+countNodes(root->right)+1;
        }

        
    }
};
// @lc code=end

