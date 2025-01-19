class Solution(object):
    def minimumTime(self, n, relations, time):
        """
        :type n: int
        :type relations: List[List[int]]
        :type time: List[int]
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of relations array #####
        len_relations = len(relations)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Edge summary counter, rank arrays #####
        edge_cnter_arry, edge_rank_arry = [0 for n_idx in range(n)], [0 for n_idx in range(n)]

        ##### Record queue #####
        record_queue = []


        ###################################################################################
        #Breath-first search based loop traversal with recorded dictionary/hashmap, arrays
        ##### Step 1: Record nodes informations with dictionary/hashmap, arrays #####
        for relations_idx in range(len_relations):
            sout_node, sin_node = ((relations[relations_idx])[0] - 1), ((relations[relations_idx])[1] - 1) #Signal input/output node

            ##### Check if the related node existed or not #####
            if (sout_node not in root_child_dict):
                root_child_dict[sout_node] = [sin_node] #Keep updating/recording
            else:
                (root_child_dict[sout_node]).append(sin_node) #Keep updating/recording

            edge_cnter_arry[sin_node] += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap, arrays #####
        for n_idx in range(n):

            ##### Check if the node's edges is 0 or not #####
            if (not edge_cnter_arry[n_idx]):
                edge_rank_arry[n_idx] = time[n_idx] #Keep updating/overwriting

                record_queue.append((n_idx, edge_rank_arry[n_idx])) #Keep updating/recording
            else:
                pass

        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                (record_node, record_rank) = record_queue.pop(0) #Record nodes value, rank

                ##### Check if the current node value existed or not #####
                if (record_node in root_child_dict):
                    for next_node in root_child_dict[record_node]:

                        ##### Check if the current node's edge rank is larger or not #####
                        if (record_rank > edge_rank_arry[next_node]):
                            edge_rank_arry[next_node] = record_rank #Keep updating/overwriting
                        else:
                            pass

                        edge_cnter_arry[next_node] -= 1 #Keep updating/reducing

                        ##### Check if the current node's edges is end of traversal or not #####
                        if (not edge_cnter_arry[next_node]):
                            edge_rank_arry[next_node] += time[next_node] #Keep updating/overwriting

                            record_queue.append((next_node, edge_rank_arry[next_node])) #Keep updating/recording
                        else:
                            pass
                else:
                    pass

        return max(edge_rank_arry)
