class Solution(object):
    def loudAndRich(self, richer, quiet):
        """
        :type richer: List[List[int]]
        :type quiet: List[int]
        :rtype: List[int]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. richer, quiet) #####
        len_richer, len_quiet = len(richer), len(quiet)

        ##### Root-child, record dictionary/hashmaps #####
        root_child_dict, record_dict = {}, {}

        ##### Edge-rank array #####
        edge_rank_arry = [0 for _ in range(len_quiet)]

        ##### Record queue #####
        record_queue = []

        ##### Result array #####
        res_arry = deepcopy(quiet)


        ###########################################################################
        #Breath-first search based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for quiet_idx in range(len_quiet):
            record_dict[quiet[quiet_idx]] = quiet_idx #Keep updating/recording
        
        for richer_idx in range(len_richer):
            curr_node, next_node = (richer[richer_idx])[0], (richer[richer_idx])[1] #Current, Next nodes

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [next_node] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append(next_node) #Keep updating/recording

            edge_rank_arry[next_node] += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_idx in range(len_quiet):

            ##### Check if the current summary counter matched conditions or not #####
            if (not edge_rank_arry[record_idx]):
                record_queue.append((record_idx, quiet[record_idx])) #Keep updating/recording

                res_arry[record_idx] = record_idx #Keep updating/overwriting
            else:
                pass

        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                (record_node, record_quiet) = record_queue.pop(0) #Record node, quietness

                ##### Check if the current node existed or not #####
                if (record_node in root_child_dict):
                    for next_node in root_child_dict[record_node]:

                        ##### Check if the next node matched conditions or not #####
                        if (res_arry[next_node] > record_quiet):
                            res_arry[next_node] = record_quiet #Keep updating/overwriting
                        else:
                            pass

                        edge_rank_arry[next_node] -= 1 #Keep updating/reducing

                        ##### Check if the current summary counter matched conditions or not #####
                        if (not edge_rank_arry[next_node]):
                            record_queue.append((next_node, res_arry[next_node])) #Keep updating/recording

                            res_arry[next_node] = record_dict[res_arry[next_node]] #Keep updating/overwriting
                        else:
                            pass
                else:
                    pass

        return res_arry
