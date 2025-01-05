class Solution(object):
    def maxProbability(self, n, edges, succProb, start_node, end_node):
        """
        :type n: int
        :type edges: List[List[int]]
        :type succProb: List[float]
        :type start_node: int
        :type end_node: int
        :rtype: float
        """
        #===================================#
        # Dijkstra's based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Edge rank array #####
        edge_rank_arry = [0.0 for n_idx in range(n)]

        ##### Record heap/priority-queue #####
        record_pq = []


        #######################################################################################
        #Dijkstra's based loop traversal with recorded heap/priority-queue, dictionary/hashmap
        heapify(record_pq) #Update/Transform

        edge_rank_arry[start_node] = 1.0 #Update/Overwrite

        heappush(record_pq, [start_node, (-1.0)]) #Update/Record

        for edges_idx in range(len_edges):

            ##### Check if the current node existed or not #####
            if ((edges[edges_idx])[0] not in record_dict):
                record_dict[(edges[edges_idx])[0]] = [[(edges[edges_idx])[1], succProb[edges_idx]]] #Keep updating/recording
            else:
                (record_dict[(edges[edges_idx])[0]]).append([(edges[edges_idx])[1], succProb[edges_idx]]) #Keep updating/recording
            
            if ((edges[edges_idx])[1] not in record_dict):
                record_dict[(edges[edges_idx])[1]] = [[(edges[edges_idx])[0], succProb[edges_idx]]] #Keep updating/recording
            else:
                (record_dict[(edges[edges_idx])[1]]).append([(edges[edges_idx])[0], succProb[edges_idx]]) #Keep updating/recording

        while (record_pq):
            [record_val, record_scl] = record_pq[0] #Nodes informations

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current node information is valid or not #####
            if (edge_rank_arry[record_val] != (record_scl * (-1))):
                continue

            ##### Check if the current node existed or not #####
            if (record_val in record_dict):
                for [next_val, next_scl] in record_dict[record_val]:
                    next_accu_scl = ((record_scl * (-1)) * next_scl)

                    ##### Check if the next node matched conditions or not #####
                    if (next_accu_scl > edge_rank_arry[next_val]):
                        edge_rank_arry[next_val] = next_accu_scl #Keep updating/overwriting

                        heappush(record_pq, [next_val, (next_accu_scl * (-1))]) #Keep updating/recording
                    else:
                        pass

        return edge_rank_arry[end_node]
