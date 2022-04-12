// 804. 唯一摩尔斯密码词
#include <vector>
#include <string>
#include <set>
using namespace std;

//哈希表(集合),模拟
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        string translate = "";
        set<string> st;

        for (auto word : words)
        {
            for (auto &c : word)
            {
                translate += morse[c - 'a'];
            }
            if (!st.count(translate))
            {
                st.insert(translate);
            }
            translate.clear();
        }
        return st.size();
    }
};