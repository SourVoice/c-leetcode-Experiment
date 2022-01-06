// 121. ������Ʊ�����ʱ��
//��̬�滮
int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize <= 1)
        return 0;
    int minBuy = prices[0];
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        minBuy = fmin(prices[i], minBuy);
        maxProfit = fmax(maxProfit, prices[i] - minBuy);
    }
    return maxProfit;
}