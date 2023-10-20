/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    vector<int> inorder;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* maketree(int si,int ei){
        if(si==ei) return new TreeNode(inorder[si]);
        if(si>ei) return nullptr;

        int mid=(si+ei)/2;
        TreeNode* node=new TreeNode(inorder[mid]);
        node->left=maketree(si,mid-1);
        node->right=maketree(mid+1,ei);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return maketree(0,inorder.size()-1);


        
        
    }
};
// @lc code=end

