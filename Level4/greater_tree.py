# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    nodeValueTotal = 0

    def convertBST(self, root: TreeNode) -> TreeNode:
        if root is not None:
            self.convertBST(root.right)
            self.nodeValueTotal = self.nodeValueTotal + root.val
            root.val = self.nodeValueTotal
            self.convertBST(root.left)
        return root
    
