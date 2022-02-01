// 2000. 反转单词前缀

#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        reverse(word.begin(), word.begin() + word.find(ch) + 1);
        return word;
    }
};

//标准
class Solution2
{
public:
    string reversePrefix(string word, char ch)
    {
        int index = word.find(ch);
        if (index != string::npos)
        {
            reverse(word.begin(), word.begin() + index + 1);
        }
        return word;
    }
};
