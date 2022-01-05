#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
char *longestPalindrome(char *s)
{

    int n = strlen(s);
    if (n == 1)
        return s;
    int substr = 0; //�Ӵ���ʼλ��
    int subend = 0; //�ӽ���ʼλ��
    int len = INT_MIN;
    for (int i = 1; i < 2 * n - 1; i++) //���Ĵ����м�չ��,ֻ��2n-1����������
    {
        int left = i / 2;                                     //
        int right = i / 2 + i % 2;                            //����ʱȡ�м�,ż��ʱȥ�ұ�
        while (left >= 0 && right < n && s[left] == s[right]) //������չ
        {
            if ((right - left + 1) > len) //�������������չ���Ĵ�
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