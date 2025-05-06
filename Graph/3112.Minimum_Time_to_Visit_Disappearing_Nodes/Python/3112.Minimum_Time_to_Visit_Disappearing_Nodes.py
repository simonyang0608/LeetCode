class Solution(object):
    def minimumTime(self, n, edges, disappear):
        """
        :type n: int
        :type edges: List[List[int]]
        :type disappear: List[int]
        :rtype: List[int]
        """
        #===================================#
        # Dijkstras' based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Edge rank array #####
        edge_rank_arry = [float("inf") for _ in range(n)]

        ##### Result array #####
        res_arry = [(-1) for _ in range(n)]


        ##################################################################
        #Dijkstras' based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for edges_idx in range(len_edges):
            curr_node, next_node, next_times = (edges[edges_idx])[0], (edges[edges_idx])[1], (edges[edges_idx])[2] #Current, Next nodes, times

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

        heappush(record_pq, (0, 0)) #Update/Record
        
        edge_rank_arry[0] = 0 #Update/Overwrite

        while (record_pq):
            (record_times, record_node) = record_pq[0] #Record times, node

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current times matched conditions or not #####
            if (edge_rank_arry[record_node] != record_times):
                continue

            res_arry[record_node] = record_times #Keep updating/overwriting

            ##### Check if the current node existed or not #####
            if (record_node in root_child_dict):
                for (next_node, sub_times) in root_child_dict[record_node]:

                    ##### Check if the next times matched conditions or not #####
                    if ((record_times + sub_times) >= disappear[next_node]):
                        continue
                    
                    next_times = (record_times + sub_times) #Next times

                    ##### Check if the next times matched conditions or not #####
                    if (edge_rank_arry[next_node] > next_times):
                        edge_rank_arry[next_node] = next_times #Keep updating/overwriting

                        heappush(record_pq, (next_times, next_node)) #Keep updating/recording
                    else:
                        pass
            else:
                pass

        return res_arry
