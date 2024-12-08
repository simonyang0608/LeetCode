"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if (not node): #Issue/Boundary-case handling
            return None

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {}

        return self.dfsTraversal(node, record_dict) #Recursion function call (i.e. whole graph node)


    def dfsTraversal(self, node, record_dict):
        """
        :type node: Node
        :type record_dict: dict
        :rtype: Node
        """
        if (node.val in record_dict): #Issue/Boundary-case handling
            return record_dict[node.val]

        ####################
        #Whole process/flow
        res_node = Node(node.val) #Result node

        record_dict[(node.val)] = res_node #Update/Record

        for record_node in node.neighbors:
            (res_node.neighbors).append(self.dfsTraversal(record_node, record_dict)) #Keep updating/recording

        return res_node
