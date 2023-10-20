/*
 * @lc app=leetcode id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* temp, int val) {
        // if(!root) return root;
        // if(root->val==val) return root;
        // if(root->val > val) return searchBST(root->left,val);
        // if(root->val < val) return searchBST(root->right,val);
        // return nullptr;

        // TreeNode* temp=root;
        while(temp){
            if(temp->val==val) return temp;
            else if(temp->val>val) 
            temp=temp->left;
            else 
            temp=temp->right;
        }
        return temp;
        
    }
};
// @lc code=end

