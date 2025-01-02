# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSubPath(self, head, root):
        """
        :type head: Optional[ListNode]
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not root): #Issue/Boundary-case handling
            return False

        if (self.dfsTraversal(head, root)): #Recursion function call (i.e. top-first root tree-node)
            return True

        return (self.isSubPath(head, root.left) or self.isSubPath(head, root.right)) #Recursion function call (i.e. following root tree-node)
        

    def dfsTraversal(self, head, root):
        """
        :type head: Optional[ListNode]
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not head): #Issue/Boundary-case handling
            return True

        if (not root): #Issue/Boundary-case handling
            return False

        if (head.val != root.val): #Issue/Boundary-case handling
            return False

        return (self.dfsTraversal(head.next, root.left) or self.dfsTraversal(head.next, root.right)) #Recursion function call (i.e. next root tree-node)
