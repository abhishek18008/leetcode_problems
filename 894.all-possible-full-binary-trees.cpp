/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
    vector<TreeNode*> solve(int n){
        if(n==1)
        {
            TreeNode* root=new TreeNode();
            return {root};
        }
        vector<TreeNode*> ans;
        
        for(int i=1;i<n;i=i+2){
            vector<TreeNode*> left=solve(i);
            vector<TreeNode*> right=solve(n-i-1);
            
            for(int i=0;i<left.size();i++){
                for(int j=0;j<right.size();j++){
                    TreeNode* node=new TreeNode();
                    node->left=left[i];
                    node->right=right[j];
                    ans.push_back(node);
                }
            }
        }
        return ans;

        
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
        
    }
};
// @lc code=end

