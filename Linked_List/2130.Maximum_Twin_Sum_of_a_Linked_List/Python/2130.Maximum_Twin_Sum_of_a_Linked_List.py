# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def pairSum(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Record pointers (i.e. slow, fast) #####
        slow_ptr = fast_ptr = head

        ##### Record stack array #####
        record_stack = []

        ##### Result maximun twins #####
        res_max_twins = 0


        ###################################################
        #Stack-based loop traversal with recorded pointers
        ##### Step 1: Record middle list-node head with pointers #####
        while (fast_ptr and fast_ptr.next):
            record_stack.append((slow_ptr.val)) #Keep updating/recording

            slow_ptr = (slow_ptr.next) #Keep updating/overwriting
            fast_ptr = (fast_ptr.next).next #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded stack array #####
        while (slow_ptr):
            curr_twins = ((slow_ptr.val) + record_stack.pop()) #Current twins

            ##### Check if the current twins is maximized or not #####
            if (curr_twins > res_max_twins):
                res_max_twins = curr_twins #Keep updating/overwriting
            else:
                pass

            slow_ptr = slow_ptr.next #Keep updating/overwriting

        return res_max_twins
