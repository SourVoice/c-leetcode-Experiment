// √Ê ‘Ã‚ 17.11. µ•¥ æ‡¿Î
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findClosest(vector<string> &words, string word1, string word2)
    {
        unordered_map<string, int> mp;
        vector<int> wd1_pos, wd2_pos;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1)
                wd1_pos.push_back(i);
            if (words[i] == word2)
                wd2_pos.push_back(i);
        }
        int i = 0, j = 0;
        int ans = INT_MAX;
        while (i < wd1_pos.size() && j < wd2_pos.size())
        {
            ans = min(ans, abs(wd1_pos[i] - wd2_pos[j]));
            if (wd1_pos[i] < wd2_pos[j])
                i++;
            else
                j++;
        }
        return ans;
    }
};

class Solution2
{
public:
    int findClosest(vector<string> &words, string word1, string word2)
    {
        int wd1_pos = 0, wd2_pos = 0;
        int ans = INT_MAX;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1)
                wd1_pos = i;
            if (words[i] == word2)
                wd2_pos = i;
            if (wd1_pos && wd2_pos)
                ans = min(ans, abs(wd2_pos - wd1_pos));
        }
        return ans;
    }
};