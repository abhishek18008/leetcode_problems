/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> ans;
    int maxi=INT_MIN;
    void dfs(TreeNode* root, int & prev, int& currlen){
        if(!root) return;


        dfs(root->left,prev,currlen);
        

        if(root->val==prev){
            currlen++;  
        }
        else 
        currlen=1;

        if(currlen==maxi){
            ans.push_back(root->val);
        }

        if(currlen>maxi){
            ans.clear();
            ans.push_back(root->val);
            maxi=currlen;
        }

        
        prev=root->val;
        dfs(root->right,prev,currlen);

    }
    vector<int> findMode(TreeNode* root) {
        
        int prev=-1;
        int currlen=1;
        dfs(root,prev,currlen);
        return ans;
    }
};
// @lc code=end

