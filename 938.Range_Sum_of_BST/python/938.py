from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
        
def rangeSumBST(root: Optional[TreeNode], low: int, high: int) -> int:
    if root == None:
        return 0
    if root.val < low or root.val > high:
        return rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high)
    else:
        return root.val + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high)

