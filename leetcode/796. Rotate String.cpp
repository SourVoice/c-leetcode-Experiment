// 796. ��ת�ַ���
#include <string>
#include <algorithm>
using namespace std;

//ģ��
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        for (int i = 0; i < s.size(); i++)
        {
            char front = s.front();
            reverse(s.begin(), s.end());
            s.pop_back();
            reverse(s.begin(), s.end());
            s.push_back(front);
            if (s == goal)
                return true;
        }
        return false;
    }
};

//���õĽⷨ,��β���
class Solution2
{
public:
    bool rotateString(string s, string goal)
    {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
