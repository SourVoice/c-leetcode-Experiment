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
        int pos = rand() % total; // �������һ��λ��
        while (true)
        {
            if (mp.count(pos))
            {
                pos = rand() % total; // ��ǰλ���ѱ���ת����������һ��λ��
            }
            else
            {
                mp[pos] = true; // ��ǰλ��δ����ת�����䷭ת���˳�ѭ��
                break;
            }
        }
        return {pos / n, pos % n}; // ����λ��
    }

    void reset()
    {
        mp.clear(); // ���map
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */