// 1342. �����ֱ�� 0 �Ĳ�������

//λ����
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
//�ݹ�
class Solution2
{
public:
    int numberOfSteps(int num)
    {
        return num ? (num & 1) ? 1 + numberOfSteps(num - 1) : 1 + numberOfSteps(num >> 1) : 0;
    }
};