// 1629. 按键持续时间最长的键
char slowestKey(int *releaseTimes, int releaseTimesSize, char *keysPressed)
{
    int max = releaseTimes[0];
    char ans = keysPressed[0];
    for (int i = 1; i < releaseTimesSize; i++)
    {
        char key = keysPressed[i];
        int time = releaseTimes[i] - releaseTimes[i - 1];
        if (time > max || (time == max && key > ans))
        {
            ans = key;
            max = time;
        }
    }
    return ans;
}