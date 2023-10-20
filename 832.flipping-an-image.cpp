/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        for(int i=0;i<n;i++){
            reverse(image[i].begin(),image[i].end());
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(image[i][j]==0)
                image[i][j]=1;
            else 
            image[i][j]=0;

            }
        }
        return image;
    }
};
// @lc code=end

