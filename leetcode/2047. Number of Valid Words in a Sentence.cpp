// leetcode\2047. Number of Valid Words in a Sentence.cpp
// discription:
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
// For example,
// words = ["practice", "makes", "perfect", "coding", "makes"].
// Given word1 = ¡°coding¡±, word2 = ¡°practice¡±, return 3.
#include <iostream>
#include <string>
#include <unordered_map>
#include <strstream>
#include <sstream> // std::stringstream

using namespace std;
class Solution
{
public:
    int countValidWords(string sentence)
    {
        unordered_map<string, int> dict; // key: word, value: frequency
        int n = sentence.size();         // length of sentence
        vector<string> tokens;           // words in sentence

        std::stringstream ss(sentence);

        string intermeidate;
        while (ss >> intermeidate)
        {
            tokens.push_back(intermeidate);
        }
        int ans = 0;
        for (auto &word : tokens)
        {
            if (isValidWord(word))
            {
                cout << "word: " << word << endl;
                ans++;
            }
        }
        return ans;
    }
    bool isValidWord(string word)
    {
        if (word.size() == 0)
            return false;
        int dashNum = 0;
        int punctionNum = 0; // number of punctuation
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] < 'a' || word[i] > 'z')
            {
                if (word[i] != '-' && word[i] != '.' && word[i] != ',' && word[i] != '|' && word[i] != '!')
                    return false;
                if (word[i] == '-')
                {
                    if (i == 0 || i == word.size() - 1)
                        return false;
                    dashNum++; // count the number of '-'
                    if ((word[i - 1] < 'a' || word[i - 1] > 'z') || (word[i + 1] < 'a' || word[i + 1] > 'z'))
                        return false;
                    if (dashNum > 1)
                        return false; // if there are more than one '-' in a word, it is invalid
                }

                if (word[i] == '.' || word[i] == ',' || word[i] == '!' || word[i] == '!')
                {
                    if (i != word.size() - 1)
                        return false;
                    if (i != 0 && word.size() == 1)
                        punctionNum++; // count the number of punctuation
                    if (i == 0 && word.size() > 1)
                        return false;
                    if (punctionNum > 1)
                        return false; // if there are more than one punctuation in a word, it is invalid
                }
            }
        }
        return true;
    }
};
