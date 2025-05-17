class Solution(object):
    def makeConnected(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if ((n - 1) > len(connections)): #Issue/Boundary-case handling
            return (-1)

        ############
        #Initialize
        ##### Length of connections array #####
        len_connections = len(connections)

        ##### Root-child array #####
        root_child_arry = [[] for _ in range(n)]

        ##### Visit array #####
        visit_arry = [False for _ in range(n)]

        ##### Result summary counter #####
        res_cnter = 0


        ########################################################
        #Recursion-based DFS loop traversal with recorded array
        ##### Step 1: Record indexed-nodes informations with array #####
        for connections_idx in range(len_connections):
            (root_child_arry[(connections[connections_idx])[0]]).append((connections[connections_idx])[1]) #Keep updating/recording
            (root_child_arry[(connections[connections_idx])[1]]).append((connections[connections_idx])[0]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        for n_idx in range(n):

            ##### Check if the current node is visited or not #####
            if (visit_arry[n_idx]):
                continue

            visit_arry[n_idx] = True #Keep updating/recording

            res_cnter += 1 #Keep updating/accumulating

            self.dfsTraversal(root_child_arry, n_idx, visit_arry) #Recursion function call

        return (res_cnter - 1)

        
    def dfsTraversal(self, root_child_arry, record_node, visit_arry):
        """
        :type root_child_arry: List[List[int]]
        :type record_node: int
        :type visit_arry: List[bool]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ####################
        #Whole process/flow
        for next_node in root_child_arry[record_node]:

            ##### Check if the current node is visited or not #####
            if (visit_arry[next_node]):
                continue

            visit_arry[next_node] = True #Keep updating/recording

            self.dfsTraversal(root_child_arry, next_node, visit_arry) #Recursion function call

        return
