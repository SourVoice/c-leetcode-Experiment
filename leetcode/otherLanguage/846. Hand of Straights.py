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
            for num in range(x, x+groupSize):  # ���鷶Χ
                if cnt[num] == 0:  # �����ڲ����γ�˳������
                    return False
                cnt[num] -= 1  # �����γ�����������,ÿ��
        return True
