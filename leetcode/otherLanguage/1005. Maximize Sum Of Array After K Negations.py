"""1005. K ��ȡ������󻯵������"""


from typing import List


class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        for i in range(k):  # ÿ�����򶼽���С�ı�ɸ�ֵ
            nums = sorted(nums)
            nums[0] = -nums[0]

        return sum(nums)
