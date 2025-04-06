class Solution(object):
    def validArrangement(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: List[List[int]]
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of pairs array #####
        len_pairs = len(pairs)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Degree dictionary/hashmap #####
        degree_dict = {}

        ##### Start node #####
        start_node = (pairs[0])[0]

        ##### Record stack #####
        record_stack = []

        ##### Record array #####
        record_arry = []

        ##### Result array #####
        res_arry = []


        #############################################################
        #Stack-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes information with dictionary/hashmap #####
        for pairs_idx in range(len_pairs):
            curr_node, next_node = (pairs[pairs_idx])[0], (pairs[pairs_idx])[1] #Current, Next node

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [next_node] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append(next_node) #Keep updating/recording

            ##### Check if the current node existed or not #####
            if (curr_node not in degree_dict):
                degree_dict[curr_node] = 1 #Keep updating/recording
            else:
                degree_dict[curr_node] += 1 #Keep updating/recording

            ##### Check if the next node existed or not #####
            if (next_node not in degree_dict):
                degree_dict[next_node] = (-1) #Keep updating/recording
            else:
                degree_dict[next_node] -= 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_node in degree_dict:

            ##### Check if the current summary counter matched conditions or not #####
            if (degree_dict[record_node] > 0):
                start_node = record_node #Keep updating/overwriting

                break

        record_stack.append(start_node) #Update/Record

        while (record_stack):
            record_node = record_stack[(-1)] #Record node

            ##### Check if the current node existed or not #####
            if (record_node in root_child_dict):
                if (root_child_dict[record_node]):
                    record_stack.append((root_child_dict[record_node]).pop()) #Keep updating/recording
                else:
                    record_arry.append(record_stack.pop()) #Keep updating/recording
            else:
                record_arry.append(record_stack.pop()) #Keep updating/recording

        for record_idx in range((len(record_arry) - 1), 0, (-1)):
            res_arry.append([record_arry[record_idx], record_arry[(record_idx - 1)]]) #Keep updating/recording

        return res_arry
