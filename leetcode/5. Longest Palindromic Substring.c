#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
char *longestPalindrome(char *s)
{

    int n = strlen(s);
    if (n == 1)
        return s;
    int substr = 0; //子串起始位置
    int subend = 0; //子结束始位置
    int len = INT_MIN;
    for (int i = 1; i < 2 * n - 1; i++) //回文串从中间展开,只有2n-1这样的中心
    {
        int left = i / 2;                                     //
        int right = i / 2 + i % 2;                            //奇数时取中间,偶数时去右边
        while (left >= 0 && right < n && s[left] == s[right]) //中心拓展
        {
            if ((right - left + 1) > len) //更新最大中心拓展回文串
            {
                len = right - left + 1;
                substr = left;
                subend = right;
            }
            left--;
            right++;
        }
    }
    char *ans = (char *)calloc(len + 1, sizeof(char));
    int k = 0;
    for (int j = substr; j < subend + 1; j++)
    {
        ans[k++] = s[j];
    }
    return ans;
}