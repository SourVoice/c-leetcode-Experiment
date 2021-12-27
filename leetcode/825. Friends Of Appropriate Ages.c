// 825.  ¡‰µƒ≈Û”—
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int numFriendRequests(int *ages, int agesSize)
{
    int *nums = (int *)calloc(121, sizeof(int));
    int reqNum = 0;
    for (int i = 0; i < agesSize; i++)
        nums[ages[i]]++;

    for (int i = 1; i <= 120; i++)
    {
        if (nums[i])
        {
            for (int j = 1; j <= 120; j++)
            {
                if (nums[j])
                {
                    if (i <= j / 2 + 7)
                        continue;
                    if (i > j)
                        continue;
                    if (i > 100 && j < 100)
                        continue;
                    if (i == j)
                        reqNum += (nums[j] - 1) * nums[j];
                    else
                        reqNum += nums[j] * nums[i];
                }
            }
        }
    }
    int ans = 0;
    ans = reqNum;
    return ans;
}
int main()
{
    // int a[5] = {30, 29, 79, 119, 70};
    int a[5] = {8, 85, 24, 85, 69};
    int ans = 0;
    ans = numFriendRequests(a, 5);
    return 0;
}
//”≈ªØ∞Ê
/*
#define MAX_LEN 121
int numFriendRequests(int* ages, int agesSize)
{
    int total = 0;
    int nums[MAX_LEN] = {0};

    for (int i = 0; i < agesSize; i++) {
        nums[ages[i]]++;
    }
    for (int i = 0; i < MAX_LEN; i++) {
        if (nums[i] == 0) {
            continue;
        }
        for (int j = 0; j < MAX_LEN; j++) {
            if (j <= 0.5 * i + 7 || j > i) {
                continue;
            }
            if (i == j) {
                total += nums[i] * (nums[i] - 1);
            } else {
                total += nums[i] * nums[j];
            }
        }
    }
    return total;
}
*/