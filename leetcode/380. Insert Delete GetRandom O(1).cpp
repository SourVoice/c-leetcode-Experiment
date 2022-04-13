// 380. O(1) ʱ����롢ɾ���ͻ�ȡ���Ԫ��
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctime>
using namespace std;

//����,��ϣ
class RandomizedSet
{
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (st.count(val))
            return false;
        st.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (!st.count(val))
            return false;
        st.erase(val);
        return true;
    }

    int getRandom()
    {
        auto randInt = rand() % st.size();
        auto it = std::begin(st);
        std::advance(it, randInt);
        return *it;
    }

private:
    std::set<int> st;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

//ʱ���Ż�
class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand((uint64_t)time(NULL));
    }

    bool insert(int val)
    {
        if (mp.count(val))
            return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!mp.count(val))
            return false;
        auto last = v.back();
        swap(v[mp[val]], v.back());
        v.pop_back();
        mp[last] = mp[val];
        mp.erase(val);
        return true;
    }

    int getRandom()
    {
        return v[rand() % v.size()];
    }

private:
    std::vector<int> v;
    std::unordered_map<int, int> mp;
};