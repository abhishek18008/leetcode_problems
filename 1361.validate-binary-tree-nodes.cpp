/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */

// @lc code=start
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int count=0;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1)
            count++;
            if(rightChild[i]!=-1)
            count++;

        }
        return count==n-1;
    }
};
// @lc code=end

