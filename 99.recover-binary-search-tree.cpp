/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    TreeNode* one;
    TreeNode* two;
    void inorder(TreeNode* root,TreeNode* & prev){
        if(!root) return;

        inorder(root->left,prev);
        if(one==nullptr && root->val < prev->val){ 
            one=prev; 
        }
        if(one!=nullptr && root->val < prev->val){ 
            two=root; 
        }
        prev=root;
        inorder(root->right,prev);

    }


    void recoverTree(TreeNode* root) {
        //maintain prev
        //one time prev> curr ---> store prev;
        // two time ---> store curr
        one=nullptr;
        two=nullptr;
        TreeNode* pre = new TreeNode(INT_MIN);
        inorder(root,pre);
        swap(one->val,two->val);
        
    }
};
// @lc code=end

