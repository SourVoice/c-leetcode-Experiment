#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 846.一手顺子(Hand of Straights)
static int cmp(const void *pa, const void *pb)
{
    return *(int *)pa - *(int *)pb;
}
struct Node
{
    int val;
    int freq;
};
bool isNStraightHand(int *hand, int handSize, int groupSize)
{
    if (handSize % groupSize != 0) //不能够匹配
        return false;
    qsort(hand, handSize, sizeof(hand[0]), cmp);
    struct Node *cnt = (struct Node *)malloc(sizeof(struct Node) * handSize);

    memset(cnt, 0, sizeof(struct Node) * handSize);
    int cardSize = 0;
    for (int i = 0; i < handSize; i++) // to determine elem's frequency in hand
    {
        if (i == 0)
        {
            cnt[cardSize].val = hand[i];
            cnt[cardSize].freq = 1;
        }
        else
        {
            if (hand[i] != cnt[cardSize].val)
                cardSize++;
            cnt[cardSize].val = hand[i];
            cnt[cardSize].freq++;
        }
    }
    int pos = 0;
    for (int i = 0; i < handSize; i++)
    {
        while (pos < cardSize && cnt[pos].freq == 0)
        {
            pos++;
        }
        if (cnt[pos].val == hand[i] && cnt[pos].freq > 0)
        {
            for (int j = 0; j < groupSize; j++)
            {
                int num = hand[i] + j;
                if (cnt[pos + j].freq > 0 && cnt[pos + j].val == num)
                {
                    cnt[pos + j].freq--;
                }
                else
                    return false;
            }
        }
    }
    free(cnt);
    return true;
}