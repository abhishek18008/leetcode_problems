/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int is,int ie,int ps,int pe){
        //base case
        if(ie<is) return nullptr;
        if(is==ie) return new TreeNode(inorder[is]);

        //find the curr node
        int currnode=postorder[pe];
        TreeNode* node=new TreeNode(currnode);
        
        int i=is;
        while(inorder[i]!=currnode){
            i++;
        }

        int leftsubtreesize=i-is;

        //find the arrays for right subtree
        node->right=build(inorder,postorder,i+1,ie,ps+leftsubtreesize,pe-1);

        //find the array for the left subtree
        node->left=build(inorder,postorder,is,i-1,ps,ps+leftsubtreesize-1);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return build(inorder,postorder,0,n-1,0,n-1);
        
    }
};
// @lc code=end

