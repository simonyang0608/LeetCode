class Solution(object):
    def countGoodNodes(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
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

        ##### Visit dictionary/hashmap #####
        visit_dict = {0: True}

        ##### Result summary counter #####
        res_cnter = [0]


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
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

        res_sum_val = self.dfsTraversal(root_child_dict, 0, visit_dict, res_cnter) #Recursion function call

        return res_cnter[0]


    def dfsTraversal(self, root_child_dict, record_node, visit_dict, res_cnter):
        """
        :type root_child_dict: dict
        :type record_node: int
        :type visit_dict: dict
        :type res_cnter: int
        :rtype: int
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ############
        #Initialize
        ##### Record flag #####
        record_flag = True

        ##### Record summary counter #####
        record_cnter = (-1)

        ##### Total summary counter #####
        total_cnter = 1


        ####################
        #Whole process/flow
        if (record_node in root_child_dict):
            for next_node in root_child_dict[record_node]:

                ##### Check if the next node existed or not #####
                if (next_node not in visit_dict):
                    visit_dict[next_node] = True #Keep updating/recording

                    sub_cnter = self.dfsTraversal(root_child_dict, next_node, visit_dict, res_cnter) #Sub-summary counter

                    ##### Check if the current summary counter matched conditions or not #####
                    if (record_cnter == (-1)):
                        record_cnter = sub_cnter #Keep updating/overwriting
                    else:
                        ##### Check if the current summary counter matched conditions or not #####
                        if (sub_cnter != record_cnter):

                            ##### Check if the current flag matched conditions or not #####
                            if (record_flag):
                                record_flag &= False #Keep updating/overwriting

                    total_cnter += sub_cnter #Keep updating/accumulating

        ##### Check if the current flag matched conditions or not #####
        if (record_flag):
            res_cnter[0] += 1 #Keep updating/accumulating

        return total_cnter
