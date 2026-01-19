import sys
import math
from typing import List, Optional, Dict, Tuple, Set
from collections import deque, defaultdict, Counter
from heapq import heappush, heappop, heapify
from functools import lru_cache, cache
from bisect import bisect_left, bisect_right
from itertools import accumulate, permutations, combinations


sys.setrecursionlimit(20000)

# ------------------------------------

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"{self.val} -> {self.next}"

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return f"Node({self.val}, left={self.left}, right={self.right})"


def build_linked_list(arr: List[int]) -> Optional[ListNode]:
    if not arr: return None
    dummy = ListNode(0)
    curr = dummy
    for val in arr:
        curr.next = ListNode(val)
        curr = curr.next
    return dummy.next

def build_tree(arr: List[Optional[int]]) -> Optional[TreeNode]:
    if not arr or arr[0] is None: return None

    root = TreeNode(arr[0])
    queue = deque([root])
    i = 1

    while i < len(arr):
        node = queue.popleft()


        if i < len(arr) and arr[i] is not None:
            node.left = TreeNode(arr[i])
            queue.append(node.left)
        i += 1


        if i < len(arr) and arr[i] is not None:
            node.right = TreeNode(arr[i])
            queue.append(node.right)
        i += 1

    return root

class Solution:
    def solve(self, nums: List[int]) -> int:

        return len(nums)



if __name__ == "__main__":
    sol = Solution()

    nums1 = [1, 2, 3, 4]
    print(f"Test 1: {sol.solve(nums1)}")


