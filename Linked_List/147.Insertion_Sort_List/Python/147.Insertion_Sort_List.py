# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #=================================#
        # Insertion-sort traversal method #
        #=================================#

        ############
        #Initialize
        ##### Result list-node head #####
        res_head = ListNode((-5001))
        (res_head.next) = head

        ###############################
        #Insertion-sort loop traversal
        while (head and (head.next)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (((head.next).val) >= (head.val)):
                head = (head.next) #Keep updating/overwriting

            else:
                record_head = (head.next) #Record list-node head
                (head.next) = ((head.next).next) #Keep updating/overwriting
                
                sorted_head = res_head #Sorted list-node head

                while ((sorted_head.next) and ((sorted_head.next).val) < (record_head.val)):
                    sorted_head = (sorted_head.next) #Keep updating/overwriting
                
                (record_head.next) = (sorted_head.next) #Keep updating/overwriting
                (sorted_head.next) = record_head #Keep updating/overwriting

        return (res_head.next)
