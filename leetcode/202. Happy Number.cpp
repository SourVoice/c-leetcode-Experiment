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
class Solution2
{
public:
    int squareFunc(int x)
    {
        int square = 0;
        while (x > 0)
        {
            square += (x % 10) * (x % 10);
            x /= 10;
        }
        return square;
    }

    bool isHappy(int n)
    {
        int fast = squareFunc(n);
        int slow = n;
        while (slow != fast && fast != 1)
        {
            slow = squareFunc(slow);
            fast = squareFunc(squareFunc(fast));
        }
        return fast == 1;
    }
};