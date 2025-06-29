class Solution(object):
    def largestPathValue(self, colors, edges):
        """
        :type colors: str
        :type edges: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of colors array #####
        len_colors = len(colors)

        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Root-child array #####
        root_child_arry = [[] for _ in range(len_colors)]

        ##### In-degree array #####
        in_degree = [0 for _ in range(len_colors)]

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [[0 for _ in range(26)] for _ in range(len_colors)]

        ##### Record queue #####
        record_queue = []

        ##### Record nodes summary counter #####
        record_node_cnter = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ###############################################################
        #Breath-first search based loop traversal with recorded arrays
        ##### Step 1: Record indexed-nodes informations with arrays #####
        for edges_idx in range(len_edges):
            (root_child_arry[(edges[edges_idx])[0]]).append((edges[edges_idx])[1]) #Keep updating/recording

            in_degree[(edges[edges_idx])[1]] += 1 #Keep updating/accumulating

        for node_idx in range(len_colors):

            ##### Check if the current nodes in-degrees matched conditions or not #####
            if (in_degree[node_idx]):
                continue

            record_queue.append(node_idx) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded arrays #####
        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                curr_node = record_queue.pop(0) #Current node

                record_node_cnter += 1 #Keep updating/accumulating

                (record_dp[curr_node])[(ord(colors[curr_node]) - 97)] += 1 #Keep updating/accumulating

                res_max_cnter = max((record_dp[curr_node])[(ord(colors[curr_node]) - 97)], 
                                     res_max_cnter) #Keep updating/overwriting

                for next_node in root_child_arry[curr_node]:
                    for chr_idx in range(26):
                        (record_dp[next_node])[chr_idx] = max((record_dp[curr_node])[chr_idx], 
                                                               (record_dp[next_node])[chr_idx]) #Keep updating/overwriting

                    in_degree[next_node] -= 1 #Keep updating/reducing

                    ##### Check if the current nodes in-degrees matched conditions or not #####
                    if (not in_degree[next_node]):
                        record_queue.append(next_node) #Keep updating/recording
                    else:
                        pass

        return ((-1) if (record_node_cnter != len_colors) else res_max_cnter)
