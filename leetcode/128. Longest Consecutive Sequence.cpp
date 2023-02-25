// 128. 最长连续序列
#include <string>
#include <stack>
#include <functional>
#include <deque>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <sstream>
using namespace std;
// 优先队列
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        priority_queue<int, vector<int>, decltype(greater<int>())> pq;
        for (auto &num : nums)
            pq.push(num);
        vector<int> seq;
        int maxLen = 0;
        while (!pq.empty())
        {
            int tmp = pq.top();
            pq.pop();
            cout << tmp << " ";
            if (seq.empty())
                seq.push_back(tmp);
            else
            {
                if (seq.back() == tmp)
                    continue;
                if (seq.back() != tmp - 1)
                {
                    seq.clear();
                    seq.push_back(tmp);
                }
                else if (seq.back() == tmp - 1)
                {
                    seq.push_back(tmp);
                }
            }
            maxLen = max(static_cast<size_t>(maxLen), seq.size());
        }
        return maxLen;
    }
};
// 哈希
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        std::set<int> st;
        for (auto &&num : nums)
            st.insert(num);
        int maxl = 0;
        for (const int &num : st)
        {
            if (!st.count(num - 1))
            {
                int curnum = num;
                int curlong = 1;
                while (st.count(curnum + 1))
                {
                    curlong++;
                    curnum++;
                }
                maxl = max(maxl, curlong);
            }
        }
        return maxl;
    }
};