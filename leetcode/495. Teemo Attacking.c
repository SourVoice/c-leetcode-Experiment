/*��Ī����*/
//�ٷ����ȶȵ���,�򵥵�һ�ι�
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
