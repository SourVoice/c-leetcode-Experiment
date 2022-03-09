// 49. 字母异位词分组
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//使用字母的出现频率作为键
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for (auto str : strs)
        {
            vector<char> count(26, 0);
            for (auto c : str)
            {
                count[c - 'a']++;
            }
            string key(count.begin(), count.end());
            hash[key].push_back(str);
        }
        for (auto it = hash.begin(); it != hash.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};

//使用排序后的字符串作为键
class Solution2
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> ans;
        for (auto str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);
        }
        for (auto elem : hash)
        {
            ans.push_back(elem.second);
        }
        return ans;
    }
};