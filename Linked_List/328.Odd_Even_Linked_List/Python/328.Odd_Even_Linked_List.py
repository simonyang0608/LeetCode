# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #==========================================#
        # In-place pointers based traversal method #
        #==========================================#
        if ((not head) or (not (head.next))): #Issue/Boundary-case handling
            return head

        ############
        #Initialize
        ##### Result/Current list-nodes (i.e. head, next-head) #####
        res_head, next_head = head, (head.next)

        res_next_head = next_head


        ########################################
        #In-place pointers based loop traversal
        while (head and (head.next)):
            head.next = (head.next).next #Keep updating/overwriting

            ##### Check if the current list-node matched conditions or not #####
            if (next_head and next_head.next):
                next_head.next = (next_head.next).next #Keep updating/overwriting

                head = head.next #Keep updating/overwriting
            else:
                pass

            next_head = next_head.next #Keep updating/overwriting

        head.next = res_next_head #Keep updating/overwriting

        return res_head
