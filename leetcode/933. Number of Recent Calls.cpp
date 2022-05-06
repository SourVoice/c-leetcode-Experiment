// 933. 最近的请求次数
#include <deque>
using namespace std;

//模拟
class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        while (!dq.empty())
        {
            int t1 = dq.front();
            if (t1 < t - 3000)
            {
                dq.pop_front();
            }
            else
            {
                break;
            }
        }
        dq.push_back(t);
        return dq.size();
    }

private:
    deque<int> dq;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */