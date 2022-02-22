// 838. ????
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == '.')
            {
                continue;
            }

            if (dominoes[i] == 'L')
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (dominoes[j] == '.')
                    {
                        dominoes[j] = 'L';
                    }
                    else
                    {
                        break;
                    }
                }
                continue;
            }

            int len = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (dominoes[j] == '.')
                {
                    dominoes[j] = 'R';
                    len++;
                }
                else
                {
                    break;
                }
            }
            int end = i + len + 1;
            if (dominoes[end] == 'R')
                continue;
            if (end == n)
            {
                break;
            }
            int pos = i + len / 2 + 1;
            if (len % 2 == 1)
            {
                dominoes[pos++] = '.';
            }

            while (pos < end)
            {
                dominoes[pos++] = 'L';
            }
            i = end;
        }
        return dominoes;
    }
};