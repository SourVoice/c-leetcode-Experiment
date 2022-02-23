// 917. 仅仅反转字母

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        vector<int> notAlpha;
        string onlyAlpha;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!isalpha(s[i]))
                notAlpha.push_back(i);
            else if (isalpha(s[i]))
                onlyAlpha.push_back(s[i]);
        }

        string ans;
        reverse(onlyAlpha.begin(), onlyAlpha.end());
        cout << onlyAlpha << endl;
        int indexOfnotAlpha = 0;
        int indexOfAlpha = 0;
        for (int i = 0; i < n; i++)
        {
            if (indexOfnotAlpha < notAlpha.size() && i == notAlpha[indexOfnotAlpha])
            {
                ans.push_back(s[notAlpha[indexOfnotAlpha]]);
                indexOfnotAlpha++;
            }
            else if (indexOfAlpha < onlyAlpha.size())
            {
                ans.push_back(onlyAlpha[indexOfAlpha]);
                indexOfAlpha++;
            }
        }
        return ans;
    }
};

//双指针
class Solution2
{
public:
    string reverseOnlyLetters(string s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            while (i < j && !isalpha(s[i]))
                i++;
            while (i < j && !isalpha(s[j]))
                j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};