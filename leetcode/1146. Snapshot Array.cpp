// 1146. ��������
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
// ��ʱ
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
// ��¼ÿһ��index�²�ͬsnapidʱ��ֵ
// ����һ���±���ԣ����ǲ���Ҫ����ÿһ��snap�Ľ����ֻ������ֵ�ı��ˣ����б�Ҫȥ����
// ����˵���±�1��snap_id=10��100,1000��ʱ��ֵ���ı䣬��ôsnap_id��10-100�Ĳ�ѯ����
// snap_id=10��ֵ,snap_id��100-1000�Ĳ�ѯ����snap_id=100��ֵ,ֻ��Ҫ��ѯupper_bound����
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
