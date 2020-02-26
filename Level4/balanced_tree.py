# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root == None:
            return True
        heightDifference = abs(self.getHeight(root.left) - self.getHeight(root.right))
        if heightDifference > 1:
            return False
        elif self.isBalanced(root.left):
            return self.isBalanced(root.right)
        return False

    def getHeight(self, root: TreeNode) -> int:
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 1
        return max(self.getHeight(root.left) + 1, self.getHeight(root.right) + 1)
