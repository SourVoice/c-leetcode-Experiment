// 146. LRU 缓存
#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
    typedef std::pair<int, int> pii;

public:
    LRUCache(int capacity) : _capacity(capacity)
    {
    }

    int get(int key)
    {
        auto it = table.find(key);
        if (it != table.end())
        {
            lru.splice(lru.begin(), lru, it->second); // get() 操作后, 更新到链表头
            return it->second->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto it = table.find(key);
        if (it != table.end())
        {
            auto lru_it = it->second;
            lru.splice(lru.begin(), lru, lru_it); // get(), 或者put()后, 更新到链表头
            lru_it->second = value;               // 更新
            return;
        }

        lru.emplace_front(make_pair(key, value));
        table[key] = lru.begin();
        if (table.size() > _capacity)
        {
            table.erase(lru.back().first); // 删除旧键
            lru.pop_back();
        }
        return;
    }

private:
    unordered_map<int, list<pii>::iterator> table;
    list<pii> lru; // store <key, value>
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */