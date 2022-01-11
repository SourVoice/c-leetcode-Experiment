// 17. 电话号码的字母组合
//哈希+回溯
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    string table[10] = {"", "", "abc",
                        "def", "ghi", "jkl",
                        "mno", "pqrs", "tuv",
                        "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return ans;
        dfs(digits, 0, string());
        return ans;
    }
    void dfs(string dig, int cur, string temp)
    {
        int digSize = (int)dig.size();
        if (cur == digSize)
        {
            ans.push_back(temp);
            return;
        }
        for (auto ch : table[dig[cur] - '0'])
            dfs(dig, cur + 1, temp + string{ch});
    }
};
