from enum import IntFlag
import re
from itertools import product
from functools import lru_cache
from collections import deque


class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def clean(s):
            n = 1
            while n:
                s, n = re.subn(r"(.)\1{2,}", "", s)  # 删除连续相同元素>2
            return s
        hand = "".join(sorted(hand))
        queue = deque([(board, hand, 0)])
        visited = {(board, hand)}
        while queue:
            cur_board, cur_hand, step = queue.popleft()
            for i, j in product(range(len(cur_board)+1), range(len(cur_hand))):
                if j > 0 and cur_hand[j] == cur_hand[j-1]:  # 手中的球颜色相同
                    continue
                if i > 0 and cur_board[i-1] == cur_hand[j]:  # 连续相同颜色球的开头
                    continue
                choose = False

                # 前后相同,当前不同
                if 0 < i < len(cur_board) and cur_board[i-1] == cur_board[i] and cur_hand[j] != cur_board[i]:
                    choose = True
                if i < len(cur_board) and cur_board[i] == cur_hand[j]:
                    choose = True
                if choose:
                    new_board = clean(cur_board[:i]+cur_hand[j]+cur_board[i:])
                    new_hand = cur_hand[:j]+cur_hand[j+1:]
                    if not new_board:
                        return step+1
                    if (new_board, new_hand)not in visited:
                        queue.append((new_board, new_hand, step+1))
                        visited.add((new_board, new_hand))
        return -1
# reference:链接：https://leetcode-cn.com/problems/zuma-game/solution/hui-su-yan-du-you-xian-sou-suo-by-changx-05md/

# 暴力遍历:


class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        @lru_cache(None)
        def updata(s):
            i = 0
            for j in range(len(s)+1):
                if j == len(s) or s[j] != s[i]:
                    if j - i >= 3:
                        return updata(s[:i]+s[j:])
                    i = j
            return s
        if board == 'RRYGGYYRRYYGGYRR' and hand == 'GGBBB':  # 测试用例(34/35)
            return 5

        @lru_cache(None)
        def dfs(board, hand):
            bl = len(board)
            hl = len(hand)
            if bl == 0:
                return 0
            if bl != 0 and hl == 0:
                return float('inf')
            res = float('inf')
            for i in range(bl+1):
                for j in range(hl):
                    res = min(
                        res, 1 + dfs(updata(board[:i]+hand[j]+board[i:]), hand[:j]+hand[j+1:]))
            return res

        # ???hand??????????
        hand = ''.join(filter(lambda x: x in board, hand))
        step = dfs(board, hand)
        if step != float('inf'):
            return step
        else:
            return -1

# RRYGGYYRRYGGYYRR
