/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        //convert f to t
        int i=0,j=0;
        int countF=0;
        int maxans=0;
        while(j<n){
            if(answerKey[j]=='F'){
                countF++;
            }
            if(countF>k){
                while(answerKey[i]!='F'){
                    i++;
                }
                i++;
                countF--;
            }
            maxans=max(maxans,j-i+1);
            j++;

        }

        //convert t to f
        i=0;
        j=0;
        int countT=0;
        while(j<n){
            if(answerKey[j]=='T'){
                countT++;
            }
            if(countT>k){
                while(answerKey[i]!='T'){
                    i++;
                }
                i++;
                countT--;
            }
            maxans=max(maxans,j-i+1);
            j++;

        }


    return maxans;
  
    }
};
// @lc code=end

