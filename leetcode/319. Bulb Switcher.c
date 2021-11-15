/*灯泡开关*/
int bulbSwitch(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        count++;
    }
    return count;
}
//求n以内的完全平方数的个数,
//只有完全平方数的因子为奇数,最终为亮