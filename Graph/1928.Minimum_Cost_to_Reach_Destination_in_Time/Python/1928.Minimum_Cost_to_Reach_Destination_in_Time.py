class Solution(object):
    def minCost(self, maxTime, edges, passingFees):
        """
        :type maxTime: int
        :type edges: List[List[int]]
        :type passingFees: List[int]
        :rtype: int
        """
        #===================================#
        # Dijkstras' based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of edges, total nodes #####
        len_edges, total_nodes = len(edges), len(passingFees)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Edge, Fee-rank arrays #####
        edge_rank_arry, fee_rank_arry = [float("inf") for _ in range(total_nodes)], [float("inf") for _ in range(total_nodes)]

        ##### Record heap/priority-queue #####
        record_pq = []


        ##################################################################
        #Dijkstras' based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for edges_idx in range(len_edges):
            curr_node, next_node, next_times = (edges[edges_idx])[0], (edges[edges_idx])[1], (edges[edges_idx])[2] #Nodes informations

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [(next_node, next_times)] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append((next_node, next_times)) #Keep updating/recording

            ##### Check if the next node existed or not #####
            if (next_node not in root_child_dict):
                root_child_dict[next_node] = [(curr_node, next_times)] #Keep updating/recording
            else:
                (root_child_dict[next_node]).append((curr_node, next_times)) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        heapify(record_pq) #Update/Heapify

        heappush(record_pq, (passingFees[0], 0, 0)) #Update/Record

        edge_rank_arry[0] = 0 #Update/Overwrite

        fee_rank_arry[0] = passingFees[0] #Update/Overwrite

        while (record_pq):
            (record_fee, record_node, record_times) = record_pq[0] #Record nodes informations

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current node reached target or not #####
            if (record_node == (total_nodes - 1)):
                return record_fee

            ##### Check if the current node existed or not #####
            if (record_node in root_child_dict):
                for (next_node, sub_times) in root_child_dict[record_node]:

                    ##### Check if the next times exceed boundary or not #####
                    if ((record_times + sub_times) > maxTime):
                        continue

                    next_times, next_fee = (record_times + sub_times), (record_fee + passingFees[next_node]) #Next times, fee

                    ##### Check if the next nodes informations matched conditions or not #####
                    if ((edge_rank_arry[next_node] > next_times) or (fee_rank_arry[next_node] > next_fee)):
                        edge_rank_arry[next_node] = next_times #Keep updating/overwriting

                        fee_rank_arry[next_node] = next_fee #Keep updating/overwriting

                        heappush(record_pq, (next_fee, next_node, next_times)) #Keep updating/recording
                    else:
                        pass
            else:
                pass

        return (-1)
