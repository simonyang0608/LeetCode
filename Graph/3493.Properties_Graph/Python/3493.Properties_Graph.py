class Solution(object):
    def numberOfComponents(self, properties, k):
        """
        :type properties: List[List[int]]
        :type k: int
        :rtype: int
        """
        #=====================================#
        # Disjoint-set based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of properties array #####
        len_properties = len(properties)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Edge-rank array #####
        edge_rank_arry = [1 for _ in range(len_properties)]

        ##### Result dictionary/hashmap #####
        res_dict = {}

        ##### Result summary counter #####
        res_cnter = 0


        ####################################################################
        #Disjoint-set based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for record_idx in range(len_properties):
            root_child_dict[record_idx] = record_idx #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_idx in range(len_properties):
            for sub_idx in range((record_idx + 1), len_properties):
                distj_node1 = self.distjSet(root_child_dict, record_idx) #Record dist-joint node-1
                distj_node2 = self.distjSet(root_child_dict, sub_idx) #Record dist-joint node-2

                ##### Check if the current dist-joint node matched conditions or not #####
                if (distj_node1 == distj_node2):
                    continue

                len_intrsct = len((set(properties[record_idx]) & set(properties[sub_idx]))) #Length of intersection values

                ##### Check if the current summary counter matched conditions or not #####
                if (len_intrsct >= k):

                    ##### Check which is the dist-joint node belongs to #####
                    if (edge_rank_arry[distj_node1] >= edge_rank_arry[distj_node2]):
                        root_child_dict[distj_node2] = distj_node1 #Keep updating/recording

                        edge_rank_arry[distj_node1] += edge_rank_arry[distj_node2] #Keep updating/accumulating
                    else:
                        root_child_dict[distj_node1] = distj_node2 #Keep updating/recording

                        edge_rank_arry[distj_node2] += edge_rank_arry[distj_node1] #Keep updating/accumulating
                else:
                    pass

        for record_idx in range(len_properties):
            distj_node3 = self.distjSet(root_child_dict, record_idx) #Record dist-joint node-3

            ##### Check if the current dist-joint node existed or not #####
            if (distj_node3 not in res_dict):
                res_dict[distj_node3] = True #Keep updating/recording

                res_cnter += 1 #Keep updating/accumulating
            else:
                pass

        return res_cnter


    def distjSet(self, root_child_dict, record_node):
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
        ##### Check if the current node matched conditions or not #####
        if (root_child_dict[record_node] != record_node):
            root_child_dict[record_node] = self.distjSet(root_child_dict, root_child_dict[record_node]) #Recursion function call

        return root_child_dict[record_node]
