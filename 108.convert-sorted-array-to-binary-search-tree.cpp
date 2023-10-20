/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* build(vector<int>& nums,int si,int ei){
        if(si>ei) return nullptr;
        //base case
        if(si==ei) return new TreeNode(nums[si]);
        
        int mid=(si+ei+1)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=build(nums,si,mid-1);
        node->right=build(nums,mid+1,ei);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return build(nums,0,n-1);

        
    }
};
// @lc code=end

