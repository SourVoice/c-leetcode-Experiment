// 2038. 如果相邻两个颜色均相同则删除当前颜色

#include <string>
using namespace std;

//非博弈论,Alice和Bob互不影响
class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int count = 0;
        int n = colors.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (colors.substr(i, i + 3) == "AAA")
                count++;
            if (colors.substr(i, i + 3) == "BBB")
                count--;
            ;
        }
        return count;
    }
};