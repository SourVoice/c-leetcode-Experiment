// 648. µ¥´ÊÌæ»»
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

//±©Á¦, ¹þÏ£±í
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_map<string, int> mp;
        for (auto elem : dictionary)
        {
            mp[elem]++;
        }
        string ret;

        string word;
        stringstream ss;
        ss << sentence;
        while (ss >> word)
        {
            string prefix;
            for (int i = 0; i < word.size(); i++)
            {
                prefix += word[i];
                if (mp.count(prefix))
                    break;
            }
            prefix += " ";
            ret += prefix;
        }
        return ret.substr(0, ret.size() - 1);
    }
};

//Ç°×ºÊ÷
struct Trie
{
    unordered_map<char, Trie *> children;
};
class Solution2
{
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie *trie = new Trie;
        for (auto &word : dictionary)
        {
            Trie *cur = trie;
            for (auto &l : word)
            {
                if (!cur->children.count(l))
                    cur->children[l] = new Trie;
                cur = cur->children[l];
            }
            cur->children['#'] = new Trie;
        }
        string ret;

        string word;
        stringstream ss;
        ss << sentence;
        while (ss >> word)
        {
            ret += findRoot(word, trie);
            ret += " ";
        }
        return ret;
    }
    string findRoot(string &word, Trie *trie)
    {
        string prefix;
        Trie *cur = trie;
        for (auto &l : word)
        {
            if (cur->children.count('#'))
            {
                return prefix;
            }
            else if (cur->children.count(l))
                prefix.push_back(l);
            else
                return word;
            cur = cur->children[l];
        }
        return prefix;
    }
};