/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string encoded;
    void dfs(TreeNode* root){
        if(!root) return ;
        dfs(root->left);
        encoded.append(to_string(root->val)+" ");
        dfs(root->right);
    }

    string serialize(TreeNode* root) {
        dfs(root);
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> inorder;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

