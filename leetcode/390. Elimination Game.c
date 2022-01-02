// 390. 消除游戏
int lastRemaining(int n)
{
    int k = n; //记录剩余数目
    int d = 2; // common diff 公差
    int m = 1; // nums of Arithmetic Sequence 要删除等差数列项数
    int a = 1; //删除后末尾留下的元素
    int b = 1; // the last num of Arithemtic Sequence
    while (k > 1)
    {
        m = (k + 1) / 2;
        b = a + (m - 1) * d;
        if (k & 1)         // judge weather from end or begin
            a = b - d / 2; // when rm from begin
        else
            a = b + d / 2; // when rm from end
        d *= -2;           //每轮反向,公差翻倍
        k /= 2;            //每轮删去一半
    }
    return a;
}
/*
1,2,3,4,5,6,7,8,9   k = 9, d = 2, m = 5, a = 1, b = a+(m-1)*d = 9
rm 1,3,5,7,9        a = b - d/2 = 8, d = -4
le 2,4,6,8          k = 4, d = -4, m = 2, a = 8, b = a + (m-1)*d = 4
rm 8,4              a = b + d/2 = 2, d = 8
le 2,6              k = 2, d = 8, m = 1, a = 2, b = a+(m-1)*d = 2
rm 2
le 6
*/