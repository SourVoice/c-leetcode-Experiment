// 202. ¿ìÀÖÊı

//¹şÏ£±í
class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> st;
        while (!st.count(n))
        {
            st.insert(n);
            int res = 0;
            while (n > 0)
            {
                res += pow(n % 10, 2);
                n /= 10;
            }
            if (res == 1)
                return true;
            n = res;
        }
        return false;
    }
};