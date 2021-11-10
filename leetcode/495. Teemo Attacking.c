/*提莫攻击*/
//官方蹭热度的题,简单到一次过
int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration)
{
    int durgtime = 0;
    for (int i = 0; i < timeSeriesSize - 1; i++)
    {
        if (timeSeries[i + 1] <= timeSeries[i] + duration - 1)
        {
            durgtime += timeSeries[i + 1] - timeSeries[i];
        }
        else
            durgtime += duration;
    }
    return durgtime + duration;
}
