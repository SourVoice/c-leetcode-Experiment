from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        visited = dict()

        for idx, val in enumerate(numbers):
            if target - val not in visited:
                visited[val] = idx
            else:
                return [visited[target - val], idx]
