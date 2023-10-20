/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    //[si, ei]
    vector<TreeNode*> solve(int si,int ei){
        vector<TreeNode*> ans;
        //base case
        if(si>ei) {
            ans.push_back(NULL);
            return ans;
        }

        
        for(int i=si;i<=ei;i++){
            //make node with val si
           
            vector<TreeNode*> leftsubtree=solve(si,i-1);
            vector<TreeNode*> rightsubtree=solve(i+1,ei);
            for(int p=0;p<leftsubtree.size();p++){
                for(int q=0;q<rightsubtree.size();q++){
                     TreeNode* root=new TreeNode(i);
                    root->left=leftsubtree[p];
                    root->right=rightsubtree[q];
                    ans.push_back(root);
                }
            }
        }
        return ans;

    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);  
    }
};
// @lc code=end

