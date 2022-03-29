
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        long temp = n ^ (n >> 1); // if n's binary is 1010..., then n^(n+1) = 0111...
        return (temp & (temp + 1)) == 0;
    }
};