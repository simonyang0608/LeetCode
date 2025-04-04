class Solution(object):
    def validPath(self, n, edges, source, destination):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Visit array #####
        visit_arry = [False for _ in range(n)]


        ####################################
        #Recursion-based DFS loop traversal
        for edges_idx in range(len_edges):
            curr_node, next_node = (edges[edges_idx])[0], (edges[edges_idx])[1] #Current, Next node

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [next_node] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append(next_node) #Keep updating/recording

            ##### Check if the next node existed or not #####
            if (next_node not in root_child_dict):
                root_child_dict[next_node] = [curr_node] #Keep updating/recording
            else:
                (root_child_dict[next_node]).append(curr_node) #Keep updating/recording
        
        return self.dfsTraversal(root_child_dict, source, destination, visit_arry)


    def dfsTraversal(self, root_child_dict, record_node, destination, visit_arry):
        """
        :type root_child_dict: dict
        :type record_node: int
        :type destination: int
        :type visit_arry: List[bool]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ####################
        #Whole process/flow
        if (not visit_arry[record_node]):
            visit_arry[record_node] = True #Update/Overwrite

            ##### Check if the current node reach target or not #####
            if (record_node == destination): 
                return True

            ##### Check if the current node existed or not #####
            if (record_node in root_child_dict):
                for next_node in root_child_dict[record_node]:

                    ##### Check if the next node reach target or not #####
                    if (self.dfsTraversal(root_child_dict, next_node, destination, visit_arry)):
                        return True

        return False
