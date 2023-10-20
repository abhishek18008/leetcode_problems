/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
    int mod = 1e9 + 7;
  
    // this will give sum of subtree
    void dfs(TreeNode* root, long long &sum){
        if(root == nullptr){
            return;
        }
        sum += root->val;
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
  
    long long f(TreeNode* root, long long &totalSum){
        if(root == nullptr){
            return 0;
        }

        long long lsum = 0;
        dfs(root->left, lsum);
        long long prod1 = ((totalSum - lsum) * lsum);

        long long rsum = 0;
        dfs(root->right, rsum);
        long long prod2 = ((totalSum - rsum) * rsum) ;

        long long maxi = max(prod1, prod2);
        long long l = f(root->left, totalSum);
        long long r = f(root->right, totalSum);

        return max(maxi, max(l, r));
    }

    int maxProduct(TreeNode* root) {
        long long totalSum = 0;
        dfs(root, totalSum);
        return f(root, totalSum)%mod;
    }
};

// @lc code=end

