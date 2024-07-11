# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of lists array #####
        len_lists = (len(lists))

        ##### Sorted array #####
        sort_arry = ([0])

        ##### Result, Dummy head #####
        res_head = dummy_head = head = (ListNode(0))


        #######################################################
        #Step 1: Updated/Recorded lists value for sorted array
        for lists_idx in range(len_lists):
            (head.next) = (lists[lists_idx]) #Next lists-indexed node connected

            ##### Keep traversing for lists-indexed node #####
            while (head and (head.next)):
                sort_arry.append(((head.next).val)) #Keep appending/recording

                head = (head.next) #Keep traversing

        sort_arry = (sorted(sort_arry[1:])) #Sorted

        len_sort_arry = (len(sort_arry)) #Length of sorted array


        #######################################################
        #Step 2: Greedy-based loop traversal with sorted array
        for sort_arry_idx in range(len_sort_arry):
            ((dummy_head.next).val) = (sort_arry[sort_arry_idx]) #Keep updating/overwriting

            dummy_head = ((dummy_head).next) #Keep traversing

        return (res_head.next)
