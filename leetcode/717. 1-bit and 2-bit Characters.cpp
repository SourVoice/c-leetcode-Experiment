// 717. 1比特与2比特字符
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size();

        int i = 0;
        while (i < n - 1)
        {
            if (bits[i] == 1)
                i += 2;
            else
                i += 1;
        }
        return i == n - 1;
    }
};

class Solution2
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size();
        int i = 0;
        while (i < n)
        {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
};