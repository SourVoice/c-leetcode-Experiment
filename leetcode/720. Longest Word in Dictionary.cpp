// 720. 词典中最长的单词
#include <vector>
#include <unordered_map>
using namespace std;

//暴力法
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        unordered_map<string, int> mp;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            mp[words[i]] = i;
        }
        string ans;
        for (int i = 0; i < n; i++)
        {
            bool find = true;
            for (int j = words[i].size() - 2; j >= 0; j--)
            {
                if (!mp.count(words[i].substr(0, j + 1)))
                {
                    find = false;
                    break;
                }
            }
            if (find)
            {
                if (words[i].size() > ans.size())
                {
                    ans = words[i];
                }
                if (words[i].size() == ans.size() && words[i] < ans)
                {
                    ans = words[i];
                }
            }
        }
        return ans;
    }
};

//字典树,trie树
class Trie
{
public:
    Trie()
    {
        this->children = vector<Trie *>(26, nullptr);
        this->isWord = false;
    }

    void insert(string &word)
    {
        Trie *node = this;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (!node->children[index])
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isWord = true;
    }

    bool search(string &word)
    {
        Trie *node = this;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (!node->children[index] || !(node->children[index]->isWord))
            {
                return false;
            }
            node = node->children[index];
        }
        return node->isWord;
    }

private:
    vector<Trie *> children;
    bool isWord;
};
class Solution2
{
public:
    string longestWord(vector<string> &words)
    {
        Trie *root = new Trie();
        for (auto word : words)
        {
            root->insert(word);
        }
        string ans = "";
        for (auto word : words)
        {
            if (root->search(word))
            {
                if (word.size() > ans.size() || (word.size() == ans.size() && word < ans))
                {
                    ans = word;
                }
            }
        }
        return ans;
    }
};