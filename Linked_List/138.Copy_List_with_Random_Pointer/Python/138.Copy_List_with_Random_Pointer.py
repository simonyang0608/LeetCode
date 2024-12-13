"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        #==================================#
        # Recursion-based traversal method #
        #==================================#
        if (not head): #Issue/Boundary-case handling
            return None

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result, Record head list-node #####
        res_head = record_head = self.recurseTraversal(head, record_dict)


        #################################################################
        #Recursion-based loop traversal with recorded dictionary/hashmap
        while (head):

            ##### Ceck if the current random pointer existed or not #####
            if (head.random):
                record_head.random = record_dict[head.random] #Keep updating/overwriting
            else:
                pass

            head = head.next #Keep updating/overwriting
            record_head = record_head.next #Keep updating/overwriting

        return res_head


    def recurseTraversal(self, head, record_dict):
        """
        :type head: Node
        :type record_dict: dict
        :rtype: Node
        """
        #====================================#
        # Recursion-based traversal function #
        #====================================#
        if (not head): #Issue/Boundary-case handling
            return None

        ####################
        #Whole process/flow
        res_head = Node(head.val) #Result head list-node

        res_head.next = self.recurseTraversal(head.next, record_dict) #Update/Overwrite

        res_head.random = None #Update/Overwrite

        record_dict[head] = res_head #Update/Record

        return res_head
