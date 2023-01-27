#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <sstream>
using namespace std;
class Solution
{
public:
    bool isNumber(string s)
    {
        if (s.empty() || s.length() == 0)
            return false;
        // 去掉首位空格
        trim(s);
        bool numFlag = false;
        bool dotFlag = false;
        bool eFlag = false;
        for (int i = 0; i < s.length(); i++)
        {
            // 判定为数字，则标记numFlag
            if (s.at(i) >= '0' && s.at(i) <= '9')
            {
                numFlag = true;
            }
            // 判定为.  需要没出现过.并且没出现过e
            else if (s.at(i) == '.' && !dotFlag && !eFlag)
            {
                dotFlag = true;
            }
            // 判定为e，需要没出现过e，并且出过数字了
            else if ((s.at(i) == 'e' || s.at(i) == 'E') && !eFlag && numFlag)
            {
                eFlag = true;
                numFlag = false; // 为了避免123e这种请求，出现e之后就标志为false
            }
            // 判定为+-符号，只能出现在第一位或者紧接e后面
            else if ((s.at(i) == '+' || s.at(i) == '-') && (i == 0 || s.at(i - 1) == 'e' || s.at(i - 1) == 'E'))
            {
            }
            // 其他情况，都是非法的
            else
            {
                return false;
            }
        }
        return numFlag;
    }
    void trim(std::string &s)
    {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
};