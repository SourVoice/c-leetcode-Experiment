// 819. 最常见的单词
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_set<string> bannedSet;
        for (auto &word : banned)
        {
            bannedSet.emplace(word);
        }
        int maxFrequency = 0;
        unordered_map<string, int> frequencies;
        string word;
        int length = paragraph.size();
        for (int i = 0; i <= length; i++)
        {
            if (i < length && isalpha(paragraph[i]))
            {
                word.push_back(tolower(paragraph[i]));
            }
            else if (word.size() > 0)
            {
                if (!bannedSet.count(word))
                {
                    frequencies[word]++;
                    maxFrequency = max(maxFrequency, frequencies[word]);
                }
                word = "";
            }
        }
        string mostCommon = "";
        for (auto &[word, frequency] : frequencies)
        {
            if (frequency == maxFrequency)
            {
                mostCommon = word;
                break;
            }
        }
        return mostCommon;
    }
};

class Solution2
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        unordered_set<string> bannedSet;
        for(auto &word: banned)
        {
            bannedSet.emplace(word);
        }
        unordered_map<string, int> frequencies;
        int maxUse = 0;
        string str = "";
        int n = paragraph.size();
        string ans;
        for(int i = 0; i<= n; i++){
            if(isalpha(paragraph[i])){
                str.push_back(tolower(paragraph[i]));
            }
            else if(!str.empty()){
                if(ans.empty())
                    ans = str;
                if(!bannedSet.count(str)){
                    frequencies[str]++;
                    if(frequencies[str] > maxUse){
                        maxUse = frequencies[str];
                        ans = str;
                    }
                }
                str.clear();
            }
        }
        return ans;
    }
};