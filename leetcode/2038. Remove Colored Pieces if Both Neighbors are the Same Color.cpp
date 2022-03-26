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
        for (int i = 1; i < n - 1; i++)
        {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                count++;
            if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                count--;
        }
        return count > 0;
    }
};