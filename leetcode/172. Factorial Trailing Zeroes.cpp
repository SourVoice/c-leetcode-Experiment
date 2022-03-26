// 172. 阶乘后的零

//对[1-n]中各因数进行因式分解
//每隔一个5, 出现一次因数5, 每隔25, 出现两个因数5, 每隔125, 出现三个因数5, ...
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n / 5)
        {
            count += n / 5;
            n = n / 5;
        }
        return count;
    }
};