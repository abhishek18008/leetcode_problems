/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    // unordered_set<int> s;
    // void makehashset(TreeNode* root){
    //     if(!root) return;
    //     s.insert(root->val);
    //     makehashset(root->left);
    //     makehashset(root->right);
    // }
    void inorder(TreeNode* root,vector<int>& sorted){
        if(!root) return;
        inorder(root->left,sorted);
        sorted.push_back(root->val);
        inorder(root->right,sorted);
    }

    bool findTarget(TreeNode* root, int k) {
        // //make a hashset
        // makehashset(root);
        // // do a iterative traversal
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     TreeNode* node=q.front();
        //     s.erase(node->val);
        //     q.pop();
        //     if(s.find(k-node->val)!=s.end())
        //     return true;
        //     s.insert(node->val);
        //     if(node->left)
        //     q.push(node->left);
        //     if(node->right)
        //     q.push(node->right);
        // }

        // return false;


        //do a inorder traversal
        vector<int> sorted;
        inorder(root,sorted);
        int n=sorted.size();

        // find the sum of k in the sorted array
        int l=0,r=n-1;
        while(l<r){
            int sum=sorted[l]+sorted[r];
            if(sum==k)
            return true;
            if(sum<k) l++;
            else if(sum>k) r--;
        }
        return false;          

        
    }
};
// @lc code=end

