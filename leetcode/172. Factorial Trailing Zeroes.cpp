// 172. �׳˺����

//��[1-n]�и�����������ʽ�ֽ�
//ÿ��һ��5, ����һ������5, ÿ��25, ������������5, ÿ��125, ������������5, ...
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