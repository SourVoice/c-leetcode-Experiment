// 1996. 游戏中弱角色的数量
// discription:
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(),
             [&](vector<int> &a, vector<int> &b)
             { return a[0] > b[0]; });
        int temp = properties[0][0];
        int ans = 0;
        unordered_map<int, vector<int>> group; // key:attack_same, value:vector<int> defense of attack_same
        for (auto &i : properties)
        {
            if (i[0] == temp)
            {
                group[temp].push_back(i[1]);
            }
            else
            {
                temp = i[0];
            }
        }

        for (auto prior = properties.begin(); prior != properties.end() - 1; prior++)
        {

            int defense = prior->back();
            for (auto elem = prior + group[prior->at(0)].size(); elem != properties.end(); elem++)
            {
                if (elem->size() == 1)
                {
                    ans += group[elem->at(0)].size();
                }
                else
                {
                    int attack = elem->at(0);
                    vector<int> temp;
                    for (auto &i : group[attack])
                    {
                        if (i < defense)
                        {
                            temp.push_back(i);
                        }
                    }
                    ans += temp.size();
                }
            }
        }
        return ans;
    }
};

//排序一遍过
class Solution2
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properities)
    {
        sort(properities.begin(), properities.end(),
             [&](vector<int> &a, vector<int> &b)
             { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });
        int maxDefense = 0;
        int ans = 0;
        for (auto &i : properities)
        {
            if (i[1] < maxDefense)
            {
                ans += 1;
            }
            else // i[1] >= maxDefense
            {
                maxDefense = i[1];
            }
        }
        return ans;
    }
};