// 729. 我的日程安排表 I
#include <set>
#include <tuple>
#include <unordered_map>
using namespace std;
class MyCalendar
{
public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto it = time.begin();
        while (it != time.end())
        {
            if (start < (*it).second && end > (*it).first)
                return false;
            it++;
        }
        time.emplace(make_pair(start, end));
        return true;
    }

private:
    set<pair<int, int>> time;
};

// solution 2
// keep elements in order, use TreeSet
class MyCalendar
{
    set<pair<int, int>> booked;

public:
    bool book(int start, int end)
    {
        auto it = booked.lower_bound({end, 0});
        if (it == booked.begin() || (--it)->second <= start)
        {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */