// 385. ÃÔÄãÓï·¨·ÖÎöÆ÷
#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

//µİ¹é
class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        if (s[0] != '[')
            return stoi(s);
        if (s.size() < 2)
            return NestedInteger();
        NestedInteger ans;
        int n = s.size();
        int start = 1, count = 0;
        for (int i = 0; i < n; i++)
        {
            if ((s[i] == ',' || i == n - 1) && count == 0) // reach the end of the layer, i==n-1 is for ("[123,[122,22],[122,[122]]]")
            {
                ans.add(deserialize(s.substr(start, i - start)));
                start++;
            }
            if (s[i] == '[')
                count++;
            if (s[i] == ']')
                count--;
        }
        return ans;
    }
};

//Õ»Ä£Äâ
class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        int n = s.size();
        static NestedInteger flag = NestedInteger(10000); // a flag to match the same layer
        vector<NestedInteger> sk;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ',')
            {
                continue;
            }
            else if (isdigit(s[i]) || s[i] == '-')
            {
                sk.push_back(NestedInteger(stoi(s.substr(i, n - i))));
                i += std::to_string(stoi(s.substr(i, n - i))).size() - 1;
            }
            else if (s[i] == '[')
            {
                sk.push_back(NestedInteger());
                sk.push_back(flag);
            }
            else if (s[i] == ']')
            {
                vector<NestedInteger> v;
                while (!sk.empty())
                {
                    NestedInteger tmp = sk.back();
                    sk.pop_back();
                    if (tmp.isInteger() && tmp.getInteger() == flag.getInteger())
                        break;
                    v.push_back(tmp);
                }
                for (auto it = v.rbegin(); it != v.rend(); it++)
                {
                    sk.back().add(*it);
                }
            }
        }
        return sk.back();
    }
};
//[123,[122,22],[122,[122]]]
//"[123,[122,22],[122,[122]]]"
//[123,456,[788,799,833],[[]],10,[]]