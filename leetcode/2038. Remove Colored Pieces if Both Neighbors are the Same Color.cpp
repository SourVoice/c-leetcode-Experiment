// 2038. �������������ɫ����ͬ��ɾ����ǰ��ɫ

#include <string>
using namespace std;

//�ǲ�����,Alice��Bob����Ӱ��
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