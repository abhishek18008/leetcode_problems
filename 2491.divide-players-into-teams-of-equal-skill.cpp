/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
class Solution
{
public:
  long long dividePlayers(vector<int> &skill)
  {

    sort(skill.begin(), skill.end());
    int i = 0, j = skill.size() - 1;
    long long ans = 0, checker = skill[i] + skill[j];
    while (i < j)
    {
      if (checker != skill[i] + skill[j])
        return -1;
      ans += skill[i++] * skill[j--];
    }
    return ans;
  }
};
// @lc code=end

