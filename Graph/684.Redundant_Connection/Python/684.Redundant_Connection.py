class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        #=====================================#
        # Disjoint-set based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Edge rank array #####
        edge_rank_arry = [1 for _ in range(len_edges)]

        ##### Result array #####
        res_arry = []


        ####################################################################
        #Disjoint-set based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record nodes informations with dictionary/hashmap #####
        for n_idx in range(1, (len_edges + 1)):
            root_child_dict[n_idx] = n_idx #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for edges_idx in range(len_edges):
            root_node1, root_node2 = self.disjointNode(root_child_dict, (edges[edges_idx])[0]), self.disjointNode(root_child_dict, (edges[edges_idx])[1]) #Root-node 1, 2

            ##### Check if the current root-node is the same or not #####
            if (root_node1 == root_node2):
                res_arry = edges[edges_idx] #Keep updating/overwriting
            else:
                ##### Check if the current edge rank is smaller or not #####
                if (edge_rank_arry[(root_node1 - 1)] > edge_rank_arry[(root_node2 - 1)]):
                    root_child_dict[root_node2] = root_node1 #Keep updating/recording

                    edge_rank_arry[(root_node1 - 1)] += 1 #Keep updating/accumulating
                else:
                    root_child_dict[root_node1] = root_node2 #Keep updating/recording

                    edge_rank_arry[(root_node2 - 1)] += 1 #Keep updating/accumulating

        return res_arry


    def disjointNode(self, root_child_dict, record_node):
        """
        :type root_child_dict: dict
        :type record_node: int
        :rtype: int
        """
        #=======================================#
        # Disjoint-set based traversal function #
        #=======================================#

        ####################
        #Whole process/flow
        ##### Check if the current node is root-node or not #####
        if (root_child_dict[record_node] != record_node):
            root_child_dict[record_node] = self.disjointNode(root_child_dict, root_child_dict[record_node]) #Recursion function call

        return root_child_dict[record_node]
