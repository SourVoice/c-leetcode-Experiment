/*����Сд*/
#define bool int
#define false 0
#define true 1
#define isBigAlpha(x) (x <= 'Z' && x >= 'A')
#define isSmallAlpha(x) (x <= 'z' && x >= 'a')

bool detectCapitalUse(char *word)
{

    char *strpos = word;
    char *strend = word + strlen(word);
    if ((isBigAlpha(*strpos) && isBigAlpha(*(strpos + 1))) || (isSmallAlpha(*strpos) && isSmallAlpha(*(strpos + 1))))
    { //ȫΪСд���д
        while (strpos < strend - 1)
        {
            if ((isBigAlpha(*strpos) && isSmallAlpha(*(strpos + 1))) || (isSmallAlpha(*strpos) && isBigAlpha(*(strpos + 1))))
            {
                return false;
            }
            strpos++;
        }
        return true;
    }
    if (isBigAlpha(*strpos) && *strpos < *(strpos + 1))
    { //��ͷΪ��д
        strpos++;
        while (strpos < strend - 1)
        {
            if (isBigAlpha(*(strpos + 1)))
            {
                return false;
            }
            strpos++;
        }
        return true;
    }
    if (strlen(word) == 1)
        return true;
    else
        return false;
}
int main()
{
    char *str = "FlaG";
    detectCapitalUse(str);
    return 0;
}