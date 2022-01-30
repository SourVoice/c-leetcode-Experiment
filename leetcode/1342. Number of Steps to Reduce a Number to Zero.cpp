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