# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #=======================================#
        # Two-pointers based traversal function #
        #=======================================#

        ############
        #Initialize
        ##### Result head list-node #####
        res_head = head = ListNode(-101)


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped traversal for left, right list-node intervals #####
        while (list1 and list2):

            ##### Check if the current list-node value is larger or not #####
            if (list1.val <= list2.val):
                head.next = list1 #Keep updating/overwriting

                list1 = list1.next #Keep traversing

            else:
                head.next = list2 #Keep updating/overwriting

                list2 = list2.next #Keep traversing

            head = head.next #Keep traversing

        ##### Step 2: Post-process/completions #####
        if (list1):
            head.next = list1 #Merge remainings

        elif (list2):
            head.next = list2 #Merge remainings

        return res_head.next
