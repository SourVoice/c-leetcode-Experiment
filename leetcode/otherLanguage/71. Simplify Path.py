# 71. ¼ò»¯Â·¾¶
import os
from typing import stack


class Solution:
    def simplifyPath(self, path: str) -> str:
        return os.path.realpath(path)


class Solution2:

    def simplify(self, path: str) -> str:
        stack = []
        for each in path.split('/'):
            if each not in [".", "..", ""]:
                stack.append()
            elif each is ".." and stack:
                stack.pop()

        return "/"+"/".join(stack)
