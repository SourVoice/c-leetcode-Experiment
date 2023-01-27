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
        // ȥ����λ�ո�
        trim(s);
        bool numFlag = false;
        bool dotFlag = false;
        bool eFlag = false;
        for (int i = 0; i < s.length(); i++)
        {
            // �ж�Ϊ���֣�����numFlag
            if (s.at(i) >= '0' && s.at(i) <= '9')
            {
                numFlag = true;
            }
            // �ж�Ϊ.  ��Ҫû���ֹ�.����û���ֹ�e
            else if (s.at(i) == '.' && !dotFlag && !eFlag)
            {
                dotFlag = true;
            }
            // �ж�Ϊe����Ҫû���ֹ�e�����ҳ���������
            else if ((s.at(i) == 'e' || s.at(i) == 'E') && !eFlag && numFlag)
            {
                eFlag = true;
                numFlag = false; // Ϊ�˱���123e�������󣬳���e֮��ͱ�־Ϊfalse
            }
            // �ж�Ϊ+-���ţ�ֻ�ܳ����ڵ�һλ���߽���e����
            else if ((s.at(i) == '+' || s.at(i) == '-') && (i == 0 || s.at(i - 1) == 'e' || s.at(i - 1) == 'E'))
            {
            }
            // ������������ǷǷ���
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