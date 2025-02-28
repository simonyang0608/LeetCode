class Solution(object):
    def minimumHammingDistance(self, source, target, allowedSwaps):
        """
        :type source: List[int]
        :type target: List[int]
        :type allowedSwaps: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. source, allowedSwaps) #####
        len_source, len_allowedSwaps = len(source), len(allowedSwaps)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Visit dictionary/hashmap #####
        visit_dict = {}

        ##### Result minimun summary counter #####
        res_min_cnter = 0


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record nodes informations with dictionary/hashmap #####
        for allowedSwaps_idx in range(len_allowedSwaps):
            curr_node, next_node = (allowedSwaps[allowedSwaps_idx])[0], (allowedSwaps[allowedSwaps_idx])[1] #Current, Next node

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

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for source_idx in range(len_source):

            ##### Check if the current node is visited or not #####
            if (source_idx in visit_dict):
                continue

            record_arry = [] #Record array

            val_dict = {} #Value dictionary/hashmap

            self.dfsTraversal(root_child_dict, record_arry, visit_dict, source_idx) #Recursion function call

            for record_val in record_arry:

                ##### Check if the current source value existed or not #####
                if (source[record_val] not in val_dict):
                    val_dict[source[record_val]] = 1 #Keep updating/recording
                else:
                    val_dict[source[record_val]] += 1 #Keep updating/recording

            for record_val in record_arry:

                ##### Check if the current target value existed or not #####
                if (target[record_val] not in val_dict):
                    res_min_cnter += 1 #Keep updating/accumulating
                else:
                    val_dict[target[record_val]] -= 1 #Keep updating/reducing

                    ##### Check if the current value is less than 0 or not #####
                    if (val_dict[target[record_val]] < 0):
                        res_min_cnter += 1 #Keep updating/accumulating
                    else:
                        pass

        return res_min_cnter

        
    def dfsTraversal(self, root_child_dict, record_arry, visit_dict, record_node):
        """
        :type root_child_dict: dict
        :type record_arry: List[int]
        :type visit_dict: dict
        :type record_node: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (record_node in visit_dict): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        visit_dict[record_node] = True #Update/Record

        record_arry.append(record_node) #Update/Record

        ##### Check if the current node existed or not #####
        if (record_node in root_child_dict):
            for next_node in root_child_dict[record_node]:
                self.dfsTraversal(root_child_dict, record_arry, visit_dict, next_node) #Recursion function call
