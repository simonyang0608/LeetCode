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
    def find_middle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[TreeNode]
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Two-pointers (i.e. slow, fast) #####
        slow = fast = head

        ###################################
        #Two-pointers based loop traversal
        while (fast and (fast.next)):
            prev_middle = slow #Previous middle node

            slow = (slow.next) #Keep updating/overwriting
            fast = ((fast.next).next) #Keep updating/overwriting

        return prev_middle


    def sortedListToBST(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[TreeNode]
        """
        #====================================================#
        # Recursion-based in-place pointers traversal method #
        #====================================================#
        if (not head): #Issue/Boundary-case handling
            return None

        if (not (head.next)): #Issue/Boundary-case handling
            return TreeNode((head.val))


        ##################################################
        #Recursion-based in-place pointers loop traversal
        ##### Step 1: Find previous middle, middle node #####
        prev_middle = self.find_middle(head) #Previous middle node

        root = TreeNode(((prev_middle.next).val)) #Root main-node

        right_half_head = ((prev_middle.next).next) #Right-half head node

        (prev_middle.next) = None #Update/Overwrite

        ##### Step 2: Looped-traversal #####
        (root.left) = self.sortedListToBST(head) #Recursion function call (i.e. root left-half node)
        (root.right) = self.sortedListToBST(right_half_head) #Recursion function call (i.e. root right-half node)

        return root
