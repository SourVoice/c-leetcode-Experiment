// 393. UTF-8 ±‡¬Î—È÷§
#include <vector>
#include <bitset>

using namespace std;

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int n = data.size();
        if (n == 1)
        {
            return !(data[0] >> 7);
        }
        for (int i = 0; i < n; i++)
        {
            cout << std::bitset<8>(data[i] & 0xff) << endl;
        }
        vector<vector<int>> dp(n, vector<int>(8, 0));
        for (int i = 0; i < n; i++)
        {
            int num = data[i];
            int mask = 1 << 7;
            int n_byte = 0;
            while (mask & num) // bytes of utf-8
            {
                n_byte += 1;
                mask = mask >> 1;
            }
            if (n_byte > 4 || n_byte == 1)
                return false;
            if (n_byte)
            {
                for (int j = i + 1, count = 1; count < n_byte; count++, j++)
                {
                    if (data[j] >> 6 != 2)
                        return false;
                    i++;
                }
            }
        }
        return true;
    }
};