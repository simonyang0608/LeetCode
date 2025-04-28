class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type k: int
        :rtype: int
        """
        #===================================#
        # Dijkstras' based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of flights array #####
        len_flights = len(flights)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Edge, Stop-rank arrays #####
        edge_rank_arry, stop_rank_arry = [float("inf") for _ in range(n)], [float("inf") for _ in range(n)]


        ##################################################################
        #Dijkstras' based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for flights_idx in range(len_flights):
            curr_node, next_node, next_wgt = (flights[flights_idx])[0], (flights[flights_idx])[1], (flights[flights_idx])[2] #Current, Next node, weight

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [(next_node, next_wgt)] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append((next_node, next_wgt)) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        heapify(record_pq) #Update/Heapify

        heappush(record_pq, (0, src, 0)) #Update/Record

        edge_rank_arry[src] = 0 #Update/Overwrite

        stop_rank_arry[src] = 0 #Update/Overwrite

        while (record_pq):
            (record_wgt, record_node, record_stops) = record_pq[0] #Record nodes informations

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current node reached target or not #####
            if (record_node == dst):
                return record_wgt

            ##### Check if the current node existed or not #####
            if (record_node in root_child_dict):
                for (next_node, sub_wgt) in root_child_dict[record_node]:

                    ##### Check if the next stops exceed boundary or not #####
                    if ((record_stops + 1) > (k + 1)):
                        continue

                    next_wgt = (record_wgt + sub_wgt) #Next weight

                    next_stops = (record_stops + 1) #Next stops

                    ##### Check if the next nodes informations matched conditions or not #####
                    if ((edge_rank_arry[next_node] > next_wgt) or (stop_rank_arry[next_node] > next_stops)):
                        edge_rank_arry[next_node] = next_wgt #Keep updating/overwriting

                        stop_rank_arry[next_node] = next_stops #Keep updating/overwriting

                        heappush(record_pq, (next_wgt, next_node, next_stops)) #Keep updating/recording
                    else:
                        pass
            else:
                pass

        return (-1)
