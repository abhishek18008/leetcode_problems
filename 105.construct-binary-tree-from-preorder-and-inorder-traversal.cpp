/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* build(vector<int> &preorder,vector<int>& inorder,int ps,int pe,int is,int ie ){
        if(ps>pe) return nullptr;
        if(is==ie) return new TreeNode(preorder[ps]);

        TreeNode* root = new TreeNode(preorder[ps]); // Use ps, not ie

        int posroot_in=is;
        while(inorder[posroot_in]!=preorder[ps]){
            posroot_in++;
        }

        int leftsize=posroot_in-is;
        //left subtree
        root->left=build(preorder,inorder,ps+1,ps+leftsize,is,posroot_in-1);


        //right subtree
        root->right=build(preorder,inorder,ps+leftsize+1,pe,posroot_in+1,ie);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        return build(preorder,inorder,0,n-1,0,n-1);
        
    }
};
// @lc code=end

