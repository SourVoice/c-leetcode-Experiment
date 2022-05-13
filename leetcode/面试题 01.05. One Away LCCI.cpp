//������ 01.05. һ�α༭
#include <string>

//ģ��
using namespace std;
class Solution
{
public:
    bool oneEditAway(string first, string second)
    {
        int len_1 = first.size(), len_2 = second.size();
        if (abs(len_1 - len_2) > 1)
            return false;
        int ixf = 0, ixs = 0;
        if (len_1 == len_2)
        {
            int diff = 0;
            while (first[ixf] && second[ixs])
            {
                if (first[ixf++] != second[ixs++])
                {
                    diff++;
                    if (diff > 1)
                        return false;
                }
            }
            return true;
        }
        else
        {
            if (len_1 > len_2)
            {
                int modify = 0;
                while (first[ixf] && second[ixs])
                {
                    if (first[ixf] != second[ixs])
                    {
                        modify++;
                        if (modify > 1)
                            return false;
                        ixf++;
                    }
                    else
                    {
                        ixf++;
                        ixs++;
                    }
                }
                return true;
            }
            else
            {
                int modify = 0;
                while (first[ixf] && second[ixs])
                {
                    if (first[ixf] != second[ixs])
                    {
                        modify++;
                        if (modify > 1)
                            return false;
                        ixs++;
                    }
                    else
                    {
                        ixs++;
                        ixf++;
                    }
                }
                return true;
            }
        }
        return true;
    }
};

// ˫ָ��
class Solution2
{
public:
    bool oneEditAway(string first, string second)
    {
        int len_1 = first.size(), len_2 = second.size();
        if (abs(len_1 - len_2) > 1)
            return false;
        if (len_1 < len_2)
            return oneEditAway(second, first); // let second argument represent the shorter one
        int ixf = 0, ixs = 0, modified = 0;
        while (ixf < len_1 && ixs < len_2)
        {
            if (first[ixf] == second[ixs])
            {
                ixf++, ixs++;
            }
            else
            {
                if (len_1 == len_2)
                {
                    ixf++, ixs++, modified++;
                }
                else
                {
                    ixf++, modified++;
                }
            }
        }
        return modified <= 1;
    }
};