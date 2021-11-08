/*������Ϸ*/
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
        if (*spos == *gpos) //��ȫƥ�䣩����ţ��+1
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
    for (int i = 0; i <= 9; i++) //ͳ����ţ��
    {
        if (recS[i] != 0 && recG[i] != 0)
        {
            B += getMin(recS[i], recG[i]); //��guess���ظ��Ĳ��ټ���
            B = B - bulls[i];
        }
    }
    char *s = (char *)malloc(sizeof(char) * 9);
    sprintf(s, "%dA%dB", A, B);
    return s;
}
