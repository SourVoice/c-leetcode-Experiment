# 372. ³¬¼¶´Î·½

from typing import List


class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        r = 1
        a %= 1337
        for i in b:
            r = pow(r, 10)*pow(a, i) % 1337

        return r
