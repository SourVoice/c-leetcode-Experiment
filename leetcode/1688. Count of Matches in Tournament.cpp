class Solution
{
public:
    int numberOfMatches(int n)
    {
        int ans = 0;
        while (n != 1)
        {
            if (n & 1)
            {
                ans += n >> 1;
                n = ((n - 1) >> 1) + 1;
            }
            else
            {
                n = n >> 1;
                ans += n;
            }
        }
        return ans;
    }
};

class Solution2
{
public:
    int numberOfMatches(int n)
    {
        return n - 1;
    }
};
