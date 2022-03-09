// 49. ��ĸ��λ�ʷ���
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//ʹ����ĸ�ĳ���Ƶ����Ϊ��
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

//ʹ���������ַ�����Ϊ��
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