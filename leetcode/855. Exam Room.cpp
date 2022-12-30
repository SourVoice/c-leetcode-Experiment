// 855. ��������
#include <string>
#include <functional>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <queue>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
using namespace std;
// ���
class ExamRoom
{
public:
    ExamRoom(int n)
    {
        this->n = n;
    }

    int seat()
    {
        if (st.size() == 0)
        {
            st.emplace(0);
            return 0;
        }
        int L = *st.begin();
        int targetIdx = 0;
        int interval = *st.begin();
        for (int R : st)
        {
            if (interval < (R - L) / 2) // Ѱ����������
            {
                interval = (R - L) / 2;
                targetIdx = (R + L) / 2; // �м�λ��
            }
            L = R;
        }
        // �Ҳ������ж�
        int specialDistToEnd = (n - 1) - *(--st.end());
        if (interval < specialDistToEnd)
        {
            targetIdx = n - 1;
        }
        st.emplace(targetIdx);
        return targetIdx;
    }

    void leave(int p)
    {
        st.erase(p);
    }

private:
    set<int> st;
    int n;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */