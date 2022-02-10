// 290. ���ʹ���
#include <unordered_map>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//��ϣ��˫ӳ��
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;

        unordered_map<string, char> mp2;
        unordered_map<char, string>::iterator it;
        string word;
        stringstream ss(s);
        int pattern_len = pattern.length();
        for (int i = 0; i < pattern_len; i++)
        {
            ss >> word;
            if (i == 0)
            {
                mp[pattern[i]] = word;
                mp2[word] = pattern[i];
            }
            else
            {
                if (mp.count(pattern[i]) || mp2.count(word))
                {
                    if (mp[pattern[i]] != word || mp2[word] != pattern[i])
                        return false;
                }
                else
                {
                    mp[pattern[i]] = word;
                    mp2[word] = pattern[i];
                }
            }
        }
        if (ss >> word)
            return false;
        return true;
    }
};