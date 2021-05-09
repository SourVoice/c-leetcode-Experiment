#include <stdio.h>
#define false 0;
#define true 1
int isPalindrome(int x)
{
    if (x < 10 && x >= 0)
        return true;

    if (x < 0 || x % 10 == 0)
        return false;

    int temp = x;
    int cout_bin = 0;
    long long chengfnag = 1;
    while (temp >= 10)
    {
        temp /= 10;
        cout_bin++;
        chengfnag *= 10;
    }
    cout_bin++;
    int head = 0, tail = 0;
    for (int i = 0; i < cout_bin / 2; i++)
    {
        head = x / chengfnag % 10;
        tail = x % 10;
        chengfnag /= 100;
        x = x / 10;
        if (head != tail)
            return false;
    }
    return true;
}
int main(void)
{
    printf("%d", isPalindrome(1001));
}