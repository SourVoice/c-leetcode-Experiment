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