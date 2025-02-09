# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #=============================================#
        # Recursion-based merge sort traversal method #
        #=============================================#
        if ((not head) or (not head.next)): #Issue/Boundary-case handling
            return head

        ############
        #Initialize
        ##### Head list-node (i.e. previous, slow, fast) #####
        prev_head = slow_head = fast_head = head

        ###########################################
        #Recursion-based merge sort loop traversal
        while (fast_head and (fast_head.next)):
            prev_head = slow_head #Keep updating/overwriting

            slow_head = slow_head.next #Keep updating/traversing

            fast_head = (fast_head.next).next #Keep updating/traversing

        prev_head.next = None #Keep updating/overwriting

        left_head = self.sortList(head) #Recursion function call (i.e. head left-half list-node) 
        right_head = self.sortList(slow_head) #Recursion function call (i.e. head right-half list-node)

        return self.mergeSort(left_head, right_head)


    def mergeSort(self, left_head, right_head):
        """
        :type left_head: Optional[ListNode]
        :type right_head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        
        ############
        #Initialize
        ##### Head list-node (i.e. result, record) #####
        res_head = record_head = ListNode((((-1) * (10 ** 5)) - 1))

        ####################
        #Whole process/flow
        while (left_head and right_head):

            ##### Check if the current list-node value is smaller or not #####
            if (left_head.val < right_head.val):
                record_head.next = left_head #Keep updating/overwriting

                left_head = left_head.next #Keep updating/traversing

            else:
                record_head.next = right_head #Keep updating/overwriting

                right_head = right_head.next #Keep updating/traversing

            record_head = record_head.next #Keep updating/traversing

        ##### Check if the remainings is left or right-half #####
        if (left_head):
            record_head.next = left_head #Keep updating/overwriting
        else:
            record_head.next = right_head #Keep updating/overwriting

        return res_head.next
