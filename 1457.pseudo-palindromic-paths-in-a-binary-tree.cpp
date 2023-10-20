/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : valhttps://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    void solve(TreeNode* root,int c){
        c=c^(1<<root->val);
        if(root->left==root->right){
            count+= c&(c-1) ?0:1;
            return;
        }
        
        if(root->left)
        solve(root->left,c);
        if(root->right)
        solve(root->right,c);
        
    }


    int pseudoPalindromicPaths (TreeNode* root) {
        // vector<int> branch(10,0);

        solve(root,0);
        return count;
        
    }
};
// @lc code=end

