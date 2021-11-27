#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution
{
private:
    int m;
    int n;
    int total;
    unordered_map<int, bool> mp;

public:
    Solution(int m, int n)
    {
        this->m = m;
        this->n = n;
        this->total = m * n;
    }

    vector<int> flip()
    {
        int pos = rand() % total; // 随机生成一个位置
        while (true)
        {
            if (mp.count(pos))
            {
                pos = rand() % total; // 当前位置已被翻转，继续找下一个位置
            }
            else
            {
                mp[pos] = true; // 当前位置未被翻转，将其翻转后退出循环
                break;
            }
        }
        return {pos / n, pos % n}; // 返回位置
    }

    void reset()
    {
        mp.clear(); // 清空map
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */