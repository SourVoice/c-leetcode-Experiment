// 1146. 快照数组
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>
using namespace std;
// 超时
class SnapshotArray
{
public:
    SnapshotArray(int length)
    {
        arr.resize(length, 0);
        callTimes = 0;
    }

    void set(int index, int val)
    {
        arr[index] = val;
    }

    int snap()
    {
        callTimes++;
        snapArr.push_back(arr);
        times.push_back(callTimes - 1);
        return callTimes - 1;
    }

    int get(int index, int snap_id)
    {
        auto it = lower_bound(times.begin(), times.end(), snap_id) - times.begin();
        return snapArr[it][index];
    }

private:
    vector<vector<int>> snapArr;
    vector<int> times;
    int callTimes;
    vector<int> arr;
};
// 记录每一个index下不同snapid时的值
// 对于一个下标而言，我们不需要储存每一次snap的结果，只有它的值改变了，才有必要去储存
// 比如说，下标1在snap_id=10，100,1000的时候值被改变，那么snap_id在10-100的查询就是
// snap_id=10的值,snap_id在100-1000的查询就是snap_id=100的值,只需要查询upper_bound即可
class SnapshotArray
{
public:
    SnapshotArray(int length)
    {
        mp.resize(length, {{0, 0}});
    }

    void set(int index, int val)
    {
        mp[index][snap_count] = val;
    }

    int snap()
    {
        return snap_count++;
    }

    int get(int index, int snap_id)
    {
        return (--mp[index].upper_bound(snap_id))->second;
    }

private:
    int snap_count = 0;
    vector<map<int, int>> mp; // index, snap_id, value
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
