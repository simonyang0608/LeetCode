class Solution(object):
    def frogPosition(self, n, edges, t, target):
        """
        :type n: int
        :type edges: List[List[int]]
        :type t: int
        :type target: int
        :rtype: float
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Root-child array #####
        root_child_arry = [[] for _ in range((n + 1))]

        ##### Visit array #####
        visit_arry = [False for _ in range((n + 1))]

        ##### Probability array #####
        prob_arry = [0.0 for _ in range((n + 1))]

        ##### Record queue #####
        record_queue = []


        ###############################################################
        #Breath-first search based loop traversal with recorded arrays
        ##### Step 1: Record indexed-nodes informations with arrays #####
        for edges_idx in range(len_edges):
            (root_child_arry[(edges[edges_idx])[0]]).append((edges[edges_idx])[1]) #Keep updating/recording
            (root_child_arry[(edges[edges_idx])[1]]).append((edges[edges_idx])[0]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded arrays #####
        visit_arry[1] = True #Update/Overwrite

        prob_arry[1] = 1.0 #Update/Overwrite

        record_queue.append(1) #Update/Record

        while (record_queue and t):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                curr_node = record_queue.pop(0) #Current node

                edge_cnter = 0 #Edge summary counter

                for next_node in root_child_arry[curr_node]:

                    ##### Check if the next node is visited or not #####
                    if (visit_arry[next_node]):
                        continue

                    edge_cnter += 1 #Keep updating/accumulating

                for next_node in root_child_arry[curr_node]:

                    ##### Check if the next node is visited or not #####
                    if (visit_arry[next_node]):
                        continue

                    visit_arry[next_node] = True #Keep updating/overwriting

                    prob_arry[next_node] = (prob_arry[curr_node] * (1.0 / edge_cnter)) #Keep updating/overwriting

                    record_queue.append(next_node) #Keep updating/recording

                ##### Check if the frog stayed at the same vertex or not #####
                if (edge_cnter):
                    prob_arry[curr_node] = 0.0 #Keep updating/overwriting
                else:
                    pass

            t -= 1 #Keep updating/reducing

        return prob_arry[target]
