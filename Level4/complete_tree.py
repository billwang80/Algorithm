# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        queue = [root]
        while queue[0] != None:
            current = queue.pop(0)
            queue.append(current.left)
            queue.append(current.right)
        while len(queue) > 0 and queue[0] == None:
            queue.pop(0)
        return len(queue) == 0
