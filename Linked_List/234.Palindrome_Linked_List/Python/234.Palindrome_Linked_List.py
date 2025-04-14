# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#
        if (not head.next): #Issue/Boundary-case handling
            return True

        ############
        #Initialize
        ##### Record head list-nodes (i.e. previous, slow, fast) #####
        prev = slow = fast = head

        ##### Record head list-nodes (i.e. reversed-last, previous) #####
        reverse_last, reverse_prev = None, None


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-traversal for searching for the middle position #####
        while (fast and fast.next):
            prev = slow #Keep updating/overwriting

            slow = slow.next #Keep updating/traversing

            fast = (fast.next).next #Keep updating/traversing

        ##### Step 2: Looped-traversal for reversing the post-part of list #####
        prev.next = None #Update/Record

        reverse_last = slow #Update/Overwrite

        while (reverse_last):
            reverse_next = reverse_last.next #Keep updating/overwriting

            reverse_last.next = reverse_prev #Keep updating/recording

            reverse_prev = reverse_last #Keep updating/overwriting

            reverse_last = reverse_next #Keep updating/overwriting

        ##### Step 3: Looped-traversal for the remained list-nodes #####
        while (head and reverse_prev):

            ##### Check if the current indexed-value matched conditions or not #####
            if (head.val != reverse_prev.val):
                return False

            head = head.next #Keep updating/traversing

            reverse_prev = reverse_prev.next #Keep updating/traversing

        return True
