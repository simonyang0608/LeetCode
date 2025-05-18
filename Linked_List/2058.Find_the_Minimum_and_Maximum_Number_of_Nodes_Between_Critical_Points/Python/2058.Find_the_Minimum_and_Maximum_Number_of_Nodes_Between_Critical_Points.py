# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Previous list-node head #####
        prev_head = head

        ##### Record previous, initialized-index #####
        prev_idx, init_idx = (-1), (-1)

        ##### Record summary counter #####
        record_cnter = 1

        ##### Result minimun distance #####
        res_min_dist = float("inf")


        #############################
        #Greedy-based loop traversal
        head = head.next #Update/Traverse

        while (head and head.next):
            curr_val = head.val #Current value

            ##### Check if the current list-node value matched conditions or not #####
            if (((prev_head.val < curr_val) and ((head.next).val < curr_val)) or
                ((prev_head.val > curr_val) and ((head.next).val > curr_val))):

                ##### Check if the previous index matched conditions or not #####
                if (prev_idx == (-1)):
                    prev_idx = record_cnter #Keep updating/overwriting

                    init_idx = prev_idx #Keep updating/overwriting
                else:
                    res_min_dist = min(res_min_dist, (record_cnter - prev_idx)) #Keep updating/overwriting

                    prev_idx = record_cnter #Keep updating/overwriting
            else:
                pass

            prev_head = head #Keep updating/overwriting

            record_cnter += 1 #Keep updating/accumulating

            head = head.next #Keep updating/traversing

        ##### Check if the index value matched conditions or not #####
        if (prev_idx == (-1)):
            return [(-1), (-1)]
        
        elif (prev_idx == init_idx):
            return [(-1), (-1)]

        return [res_min_dist, (prev_idx - init_idx)]
