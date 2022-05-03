// 937. 重新排列日志文件
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> character;
        vector<string> digit;
        for (auto &log : logs)
        {
            if (isdigit(log[log.find(' ') + 1]))
                digit.push_back(log);
            else
                character.push_back(log);
        }
        sort(character.begin(), character.end(), [](const string &a, const string &b)
             {
                 int i = a.find(' ');
                 int j = b.find(' ');
                 if (a.substr(i + 1) == b.substr(j + 1))
                     return a < b;
                 else
                     return a.substr(i + 1) < b.substr(j + 1); });
        vector<string> ans;
        // merge two vector
        for (auto &c : character)
            ans.push_back(c);
        for (auto &d : digit)
            ans.push_back(d);
        return ans;
    }
};