// 824. É½ÑòÀ­¶¡ÎÄ
#include <vector>
#include <string>
#include <set>
#include <sstream>
using namespace std;
class Solution
{
public:
    string toGoatLatin(string sentence)
    {
        set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<string> words;
        istringstream iss(sentence);
        string word;
        while (iss >> word)
        {
            words.push_back(word);
        }
        int cnt = 1;

        for (auto &elem : words)
        {
            if (vowel.find(elem[0]) != vowel.end())
            {
                elem += "ma";
            }
            else
            {
                elem = elem.substr(1) + elem[0] + "ma";
            }
            for (int i = 0; i < cnt; i++)
            {
                elem += "a";
            }
            cnt++;
        }
        string ans;
        // fill ans
        for (auto elem : words)
        {
            ans += elem + " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};