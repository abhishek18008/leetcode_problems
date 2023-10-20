/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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
    void dfs(TreeNode* root,vector<int>& inorder){
        if(!root) return;
        dfs(root->left,inorder);
        inorder.push_back(root->val);
        dfs(root->right,inorder);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        dfs(root1,v1);
        dfs(root2,v2);
        vector<int> ans;
        int i=0;
        int j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        if(i==v1.size()){
            while(j<v2.size()){
                ans.push_back(v2[j]);
                j++;
            }
        }
        if(j==v2.size()){
            while(i<v1.size()){
                ans.push_back(v1[i]);
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end

