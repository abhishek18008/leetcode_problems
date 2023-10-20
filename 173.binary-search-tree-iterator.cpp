/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
    private:
        vector<int> inorder;
        int nextidx;
        void dfs(TreeNode* root){
            if(!root) return;
            dfs(root->left);
            inorder.push_back(root->val);
            dfs(root->right);
        }
public:
    BSTIterator(TreeNode* root) {
        inorder.push_back(0);
        nextidx=1;
        dfs(root);
    }
    
    int next() {
        if(hasNext())
        {
            int toreturn= inorder[nextidx];
            nextidx++;
            return toreturn;
        }
        return -1; 
    }
    
    bool hasNext() {
        if(nextidx==inorder.size()) return false;
        else 
        return true;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

