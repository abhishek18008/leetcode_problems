/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution {
public:
     bool check(int present_day, vector<int> bloomDay, int required_bouquet, int required_flower)
{
   int flower_count=0;
   int bouquet_count =0;
   for(int i=0;i<bloomDay.size(); i++)
   {
   	// when this flower is already blossomed so we can include this   flower.
   	if(bloomDay[i] <= present_day)
   	{
   		flower_count++;
   		if(flower_count == required_flower)
   		{
   			bouquet_count++;
   			flower_count =0;
   		}
   	}

   	// when the flower has not blosssomed we can not include
   	// so it breaks the chain.
   	else
   	{
   		flower_count = 0;

   	}
   }

   if(bouquet_count >= required_bouquet) return true;
   else return false;

}

int minDays(vector<int>& bloomDay, int m, int k) {
   
   if((long long)m*k > bloomDay.size()) return -1;
   
   
       int lower = *min_element(bloomDay.begin(), bloomDay.end());
       int upper = *max_element(bloomDay.begin(), bloomDay.end());

       while(lower < upper)
       {
       	int mid = lower + (upper - lower)/2;

       	if(check(mid , bloomDay , m , k)) upper = mid;
       	else lower = mid +1;

       }

       return lower;
   }
};
// @lc code=end

