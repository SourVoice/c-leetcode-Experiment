"""1005. K 次取反后最大化的数组和"""


from typing import List


class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        for i in range(k):  # 每次排序都将最小的变成负值
            nums = sorted(nums)
            nums[0] = -nums[0]

        return sum(nums)
