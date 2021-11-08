/*猜数游戏*/
int getMin(int a, int b)
{
    return a < b ? a : b;
}

char *getHint(char *secret, char *guess)
{
    int A = 0, B = 0;
    char *spos = secret;
    char *gpos = guess;
    int recS[10] = {0};
    int recG[10] = {0};

    int bulls[10] = {0};
    while (spos < strlen(secret) + secret)
    {
        if (*spos == *gpos) //完全匹配），公牛数+1
        {
            A++;
            bulls[(*spos) - '0']++;
        }
        else
        {
            recS[((*spos) - '0')]++;
            recG[((*gpos) - '0')]++;
        }
        spos++;
        gpos++;
    }
    for (int i = 0; i <= 9; i++) //统计奶牛数
    {
        if (recS[i] != 0 && recG[i] != 0)
        {
            B += getMin(recS[i], recG[i]); //在guess中重复的不再计数
            B = B - bulls[i];
        }
    }
    char *s = (char *)malloc(sizeof(char) * 9);
    sprintf(s, "%dA%dB", A, B);
    return s;
}
