/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
    int maxsum;
    bool solve(TreeNode* root,int mini,int maxi,int & sum){
        if(!root) return true;

        if(mini< root->val && root->val<maxi){
            if(solve(root->left,mini,root->val,sum)  && solve(root->right,root->val,maxi,sum)){
                sum+=root->val;
                maxsum=max(sum,maxsum);
            }
        }
    }

    int maxSumBST(TreeNode* root) {
        int sum=0;
        solve(root,-10000,10000,0);
        return maxsum;
        
    }
};
// @lc code=end

