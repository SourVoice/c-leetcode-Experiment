// 1716. 计算力扣银行的钱
//简单模拟
int totalMoney(int n)
{
    int left = n % 7;
    int times = n / 7;
    int moneySave = 0;
    for (int i = 1; i <= times; i++)
        moneySave += (i + i + 6) * 7 / 2;
    moneySave += (times + 1 + times + left) * left / 2;
    return moneySave;
}