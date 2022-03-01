// 6. Z ×ÖÐÎ±ä»»
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector<string> v(min(numRows, int(s.size())));
        int diag = numRows - 2;
        if (numRows == 1)
            return s;
        int turn = 0;
        int len = s.length();
        int row = 0;
        for (int i = 0; i < len; i++)
        {
            if (row == numRows - 1)
            {
                turn = 1;
            }
            if (row == 0)
            {
                turn = 0;
            }
            v[row].push_back(s[i]);
            if (turn == 0)
            {
                row++;
            }
            else
            {
                row--;
            }
        }
        string ans;
        for (int i = 0; i < numRows; i++)
        {
            ans += v[i];
        }
        return ans;
    }
};