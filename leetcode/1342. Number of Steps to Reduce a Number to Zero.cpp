// 1342. 将数字变成 0 的操作次数

//位运算
class Solution
{
public:
    int numberOfSteps(int num)
    {
        int step = 0;
        if (num & 1)
        {
            num--;
            step++;
        }
        else
        {
            num = num >> 1;
            step++;
        }
        return step;
    }
};
//递归
class Solution2
{
public:
    int numberOfSteps(int num)
    {
        return num ? (num & 1) ? 1 + numberOfSteps(num - 1) : 1 + numberOfSteps(num >> 1) : 0;
    }
};
//位运算
class Solution3
{
public:
    int length(uint num)
    {
        uint clz = 0;
        if ((num >> 16) == 0)
        {
            clz += 16;
            num <<= 16;
        }
        if ((num >> 24) == 0)
        {
            clz += 8;
            num <<= 8;
        }
        if ((num >> 28) == 0)
        {
            clz += 4;
            num <<= 4;
        }
        if ((num >> 30) == 0)
        {
            clz += 2;
            num <<= 2;
        }
        if ((num >> 31) == 0)
        {
            clz += 1;
        }
        return 32 - clz;
    }

    int count(int num)
    {
        num = (num & 0x55555555) + ((num >> 1) & 0x55555555);
        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
        num = (num & 0x0F0F0F0F) + ((num >> 4) & 0x0F0F0F0F);
        num = (num & 0x00FF00FF) + ((num >> 8) & 0x00FF00FF);
        num = (num & 0x0000FFFF) + ((num >> 16) & 0x0000FFFF);
        return num;
    }

    int numberOfSteps(int num)
    {
        return num == 0 ? 0 : length(num) - 1 + count(num);
    }
};
