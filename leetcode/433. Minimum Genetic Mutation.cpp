// 433. 最小基因变化
#include <deque>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// bfs+ 哈希表+ 队列
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        set<string> st(bank.begin(), bank.end());
        deque<string> dq;
        dq.push_back(start);
        unordered_map<string, int> mp;
        mp[start] = 0;
        while (!dq.empty())
        {
            string head = dq.front();
            dq.pop_front();
            for (int i = 0; i < 8; i++)
            {
                for (auto &ch : vc)
                {
                    if (ch != head[i]) // choose one character to change
                    {
                        string tmp = head;
                        int step = mp[tmp];
                        tmp[i] = ch;
                        if (st.count(tmp) && !mp.count(tmp)) // the new string is in the bank and not visited
                        {
                            if (tmp == end)
                                return step + 1;
                            mp[tmp] = step + 1;
                            dq.push_back(tmp);
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    const vector<char> vc = {'A', 'C', 'G', 'T'};
};