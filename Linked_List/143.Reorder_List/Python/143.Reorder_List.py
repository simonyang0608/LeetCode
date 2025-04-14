# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: None Do not return anything, modify head in-place instead.
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Record head list-nodes (i.e. slow, fast) #####
        slow = fast = head


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-traversal for searching for the middle position #####
        while (fast and fast.next):
            slow = slow.next #Keep updating/traversing

            fast = (fast.next).next #Keep updating/traversing

        ##### Step 2: Looped-traversal for reversing the post-part of list #####
        reverse_last, reverse_prev = slow.next, None #Reverse list-nodes (i.e. last, previous)

        slow.next = None #Update/Overwrite

        while (reverse_last):
            reverse_next = reverse_last.next #Reverse-next list-node

            reverse_last.next = reverse_prev #Keep updating/recording

            reverse_prev = reverse_last #Keep updating/overwriting

            reverse_last = reverse_next #Keep updating/overwriting

        ##### Step 3: Looped-traversal for the remained-part of list #####
        while (head):

            ##### Check if the current reverse list-node existed or not #####
            if (reverse_prev):
                curr_prev = reverse_prev #Current previous list-node

                reverse_prev = reverse_prev.next #Keep updating/traversing

                curr_prev.next = head.next #Keep updating/recording

                head.next = curr_prev #Keep updating/recording

                head = curr_prev.next #Keep updating/overwriting
            else:
                head = head.next #Keep updating/traversing
