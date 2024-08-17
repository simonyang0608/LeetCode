"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not head): #Issue/Boundary-case handling
            return None

        ############
        #Initialize
        ##### Result array #####
        res_arry = []

        ##### Previous head node #####
        prev_node = None


        ####################################
        #Recursion-based DFS loop traversal
        ##### Step 1: Recursion function call (i.e. head node) #####
        self.DFS_Traversal(head, res_arry)

        ##### Step 2: Post-process/Final completions #####
        len_res_arry = (len(res_arry) - 1) #Length of result array

        for res_arry_idx in range(len_res_arry):
            (res_arry[res_arry_idx].next) = res_arry[(res_arry_idx + 1)] #Keep updating/overwriting
            (res_arry[res_arry_idx].prev) = prev_node #Keep updating/overwriting
            (res_arry[res_arry_idx].child) = None #Keep updating/overwriting

            prev_node = res_arry[res_arry_idx] #Keep updating/overwriting

        res_arry[len_res_arry].next = None #Keep updating/overwriting
        res_arry[len_res_arry].prev = prev_node #Keep updating/overwriting
        res_arry[len_res_arry].child = None #Keep updating/overwriting

        return res_arry[0]
    

    def DFS_Traversal(self, head, res_arry):
        """
        :type head: Node
        :type res_arry: List[Node]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not head): #Issue/Boundary-case handling
            return

        res_arry.append(head) #Update/Record

        ####################
        #Whole process/flow
        self.DFS_Traversal((head.child), res_arry) #Recursion function call (i.e. child node)
        self.DFS_Traversal((head.next), res_arry) #Recursion function call (i.e. next node)
