class Solution(object):
    def minReorder(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of connections array #####
        len_connections = len(connections)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Visit array #####
        visit_arry = [False for _ in range(n)]

        ##### Result minimun summary counter #####
        res_min_cnter = [0]


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record nodes informations with dictionary/hashmap #####
        for connections_idx in range(len_connections):
            start_node, end_node = (connections[connections_idx])[0], (connections[connections_idx])[1] #Start, End node

            ##### Check if the current nodes value existed or not #####
            if (start_node not in root_child_dict):
                root_child_dict[start_node] = [end_node] #Keep updating/recording
            else:
                (root_child_dict[start_node]).append(end_node) #Keep updating/recording

            if (end_node not in root_child_dict):
                root_child_dict[end_node] = [((-1) * start_node)] #Keep updating/recording
            else:
                (root_child_dict[end_node]).append(((-1) * start_node)) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        self.dfsTraversal(root_child_dict, visit_arry, 0, res_min_cnter) #Recursion function call

        return res_min_cnter[0]


    def dfsTraversal(self, root_child_dict, visit_arry, record_val, res_min_cnter):
        """
        :type root_child_dict: dict
        :type visit_arry: List[bool]
        :type record_val: int
        :type res_min_cnter: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ####################
        #Whole process/flow
        visit_arry[record_val] = True #Update/Overwrite

        ##### Check if the current nodes value existed or not #####
        if (record_val in root_child_dict):
            for next_val in root_child_dict[record_val]:

                ##### Check if the next nodes value is visited or not #####
                if (not visit_arry[abs(next_val)]):
                    res_min_cnter[0] += (1 if (next_val > 0) else 0) #Keep updating/accumulating

                    self.dfsTraversal(root_child_dict, visit_arry, abs(next_val), res_min_cnter) #Recursion function call
