// 706. 设计哈希映射
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class MyHashMap
{
public:
    MyHashMap()
    {
        map.resize(size);
    }

    void put(int key, int value)
    {
        int index = key % size;
        auto &row = map[index]; //必须使用左值引用否则无法修改
        auto it = row.begin();
        for (; it != row.end(); it++)
        {
            if (it->first == key)
                it->second = value;
        }
        row.push_back({key, value});
    }

    int get(int key)
    {
        int index = key % size;
        auto &row = map[index];
        auto it = row.begin();
        for (; it != row.end(); it++)
        {
            if (it->first == key)
                return it->second;
        }
        return -1;
    }

    void remove(int key)
    {
        int index = key % size;
        auto &row = map[index];
        auto it = row.begin();
        for (; it != row.end(); it++)
        {
            if (it->first == key)
                row.erase(it);
            it--;
        }
        return;
    }

private:
    vector<vector<pair<int, int>>> map; // list -> key:val, key:val
    int size = 1e5;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
