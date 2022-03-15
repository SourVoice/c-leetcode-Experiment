// 599. 两个列表的最小索引总和

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> mp;
        vector<string> ans;
        int n1 = list1.size(), n2 = list2.size();
        for (int i = 0; i < n1; i++)
        {
            if (!mp.count(list1[i]))
            {
                mp.insert({list1[i], i});
            }
        }

        int min = INT_MAX;
        for (int i = 0; i < n2; i++)
        {
            if (mp.count(list2[i]))
            {
                if (i > min)
                {
                    return ans;
                }

                if (mp[list2[i]] + i < min)
                {
                    min = mp[list2[i]] + i;
                    ans.clear();
                    ans.push_back(list2[i]);
                }
                else if (mp[list2[i]] + i == min)
                {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};