/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(ListNode* head,ListNode* end){
        // if(head==nullptr) return nullptr;
        if(head==end) return nullptr;


        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=end && fast->next!=end  ){
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode* node=new TreeNode(slow->val);
        node->left=solve(head,slow);
        node->right=solve(slow->next,end);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head,nullptr);
        
    }
};
// @lc code=end

