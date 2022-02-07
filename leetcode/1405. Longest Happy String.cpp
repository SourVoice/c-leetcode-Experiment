// 1405. 最长快乐字符串
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//贪心算法
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans = "";
        vector<pair<int, char>> num{{a, 'a'}, {b, 'b'}, {c, 'c'}};

        while (true)
        {
            sort(num.begin(), num.end(), [](const auto &a, const auto &b)
                 { return a.first > b.first; }); //选择最多的元素s
            bool flag = false;
            for (auto &[_, ch] : num)
            {
                //三个连续的出现
                if (_ <= 0)
                {
                    break;
                }
                if (ans.size() >= 2 && ans.back() == ch && ans[ans.size() - 2] == ch)
                {
                    continue;
                }
                ans.push_back(ch);
                _--;
                flag = true;
                break;
            }
            if (!flag)
            {
                break;
            }
        }
        return ans;
    }
};