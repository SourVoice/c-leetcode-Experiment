from typing import Counter


class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize > 0:
            return False
        hand.sort()
        cnt = Counter(hand)
        for x in hand:
            if cnt[x] == 0:
                continue
            for num in range(x, x+groupSize):  # 该组范围
                if cnt[num] == 0:  # 该组内不能形成顺子序列
                    return False
                cnt[num] -= 1  # 该组形成了有序序列,每个
        return True
