class Solution(object):
    def buildMatrix(self, k, rowConditions, colConditions):
        """
        :type k: int
        :type rowConditions: List[List[int]]
        :type colConditions: List[List[int]]
        :rtype: List[List[int]]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. rowConditions, colConditions) #####
        len_rowConditions, len_colConditions = len(rowConditions), len(colConditions)

        ##### Record dictionary/hashmaps (i.e. rows, columns) #####
        record_dict_rows, record_dict_cols = {}, {}

        ##### Record dictionary/hashmap (i.e. positions) #####
        record_dict_pos = {}

        ##### Record queue #####
        record_queue = []

        ##### Edge-rank array #####
        edge_rank_arry = [0 for _ in range(k)]

        ##### Result array #####
        res_arry = [[0 for _ in range(k)] for _ in range(k)]


        ###########################################################################
        #Breath-first search based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Looped-traversal for the indexed-nodes informations within rows positions #####
        for rowConditions_idx in range(len_rowConditions):
            curr_node, next_node = ((rowConditions[rowConditions_idx])[1] - 1), ((rowConditions[rowConditions_idx])[0] - 1) #Current, Next nodes

            ##### Check if the current node existed or not #####
            if (curr_node not in record_dict_rows):
                record_dict_rows[curr_node] = [next_node] #Keep updating/recording
            else:
                (record_dict_rows[curr_node]).append(next_node) #Keep updating/recording

            edge_rank_arry[next_node] += 1 #Keep updating/accumulating

        record_flag_rows = self.bfsTraversal(k, record_dict_rows, edge_rank_arry, record_dict_pos, record_queue, 'r') #Record flag (i.e. rows)

        if (not record_flag_rows): #Issue/Boundary-case handling
            return []

        ##### Step 2: Looped-traversal for the indexed-nodes informations within columns positions #####
        for colConditions_idx in range(len_colConditions):
            curr_node, next_node = ((colConditions[colConditions_idx])[1] - 1), ((colConditions[colConditions_idx])[0] - 1) #Current, Next nodes

            ##### Check if the current node existed or not #####
            if (curr_node not in record_dict_cols):
                record_dict_cols[curr_node] = [next_node] #Keep updating/recording
            else:
                (record_dict_cols[curr_node]).append(next_node) #Keep updating/recording

            edge_rank_arry[next_node] += 1 #Keep updating/accumulating

        record_flag_cols = self.bfsTraversal(k, record_dict_cols, edge_rank_arry, record_dict_pos, record_queue, 'c') #Record flag (i.e. columns)

        if (not record_flag_cols): #Issue/Boundary-case handling
            return []

        for record_key in record_dict_pos:
            (res_arry[(record_dict_pos[record_key])[0]])[(record_dict_pos[record_key])[1]] = (record_key + 1) #Keep updating/overwriting

        return res_arry


    def bfsTraversal(self, k, record_dict_all, edge_rank_arry, record_dict_pos, record_queue, record_chr):
        """
        :type k: int
        :type record_dict_all: dict
        :type edge_rank_arry: List[int]
        :type record_dict_pos: dict
        :type record_queue: List[int]
        :type record_chr: char
        :rtype: bool
        """
        #==============================================#
        # Breath-first search based traversal function #
        #==============================================#

        ############
        #Initialize
        ##### Record positions index #####
        record_pos_idx = (k - 1)

        ##### Result summary counter #####
        res_cnter = 0


        ####################
        #Whole process/flow
        ##### Step 1: Record indexed-nodes informations with array #####
        for record_idx in range(k):
            
            ##### Check if the current summary counter matched conditions or not #####
            if (not edge_rank_arry[record_idx]):

                ##### Check if the current char matched conditions or not #####
                if (record_chr == 'r'):
                    record_dict_pos[record_idx] = [record_pos_idx] #Keep updating/recording
                else:
                    (record_dict_pos[record_idx]).append(record_pos_idx) #Keep updating/recording

                record_pos_idx -= 1 #Keep updating/reducing

                record_queue.append(record_idx) #Keep updating/recording

                res_cnter += 1 #Keep updating/accumulating
            else:
                pass

        ##### Step 2: Looped-traversal with recorded array #####
        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                record_node = record_queue.pop(0) #Record node

                ##### Check if the current node existed or not #####
                if (record_node in record_dict_all):
                    for next_node in record_dict_all[record_node]:
                        edge_rank_arry[next_node] -= 1 #Keep updating/reducing

                        ##### Check if the current summary counter matched conditions or not #####
                        if (not edge_rank_arry[next_node]):

                            ##### Check if the current char matched conditions or not #####
                            if (record_chr == 'r'):
                                record_dict_pos[next_node] = [record_pos_idx] #Keep updating/recording
                            else:
                                (record_dict_pos[next_node]).append(record_pos_idx) #Keep updating/recording

                            record_pos_idx -= 1 #Keep updating/reducing

                            record_queue.append(next_node) #Keep updating/recording

                            res_cnter += 1 #Keep updating/accumulating
                        else:
                            pass
                else:
                    pass

        return (True if (res_cnter == k) else False)
