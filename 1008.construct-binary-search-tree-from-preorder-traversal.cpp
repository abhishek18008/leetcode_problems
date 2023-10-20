/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* solve(vector<int> & preorder,int start,int end){

        //base case
        if(start>end) return NULL;

        TreeNode* root=new TreeNode(preorder[start]);
        
        int idx=start + 1;  // Start from the next element
        while(idx <= end && preorder[idx] < preorder[start]){
            idx++;
        }
        root->left=solve(preorder,start+1,idx-1);
        root->right=solve(preorder,idx,end);
        return root;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
         return solve(preorder,0,preorder.size()-1);
    }
};
// @lc code=end

