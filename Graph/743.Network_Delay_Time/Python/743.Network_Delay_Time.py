class Solution(object):
    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        #===================================#
        # Dijkstra's based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of times array #####
        len_times = len(times)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Edge rank array #####
        edge_rank_arry = [float('inf') for _ in range(n)]

        ##### Result summary counter #####
        res_cnter = 0


        ##################################################################
        #Dijkstra's based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes information with dictionary/hashmap #####
        for times_idx in range(len_times):
            record_node, next_node, next_wgt = ((times[times_idx])[0] - 1), ((times[times_idx])[1] - 1), (times[times_idx])[2] #Record/Next node, weight

            ##### Check if the current indexed-node existed or not #####
            if (record_node not in root_child_dict):
                root_child_dict[record_node] = [[next_node, next_wgt]] #Keep updating/recording
            else:
                (root_child_dict[record_node]).append([next_node, next_wgt]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        heapify(record_pq) #Update/Heapify

        heappush(record_pq, [0, (k - 1)]) #Update/Record

        edge_rank_arry[(k - 1)] = 0 #Update/Overwrite

        while (record_pq):
            record_node, record_wgt = (record_pq[0])[1], (record_pq[0])[0] #Record node, weight

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current summary counter matched conditions or not #####
            if (edge_rank_arry[record_node] != record_wgt):
                continue

            res_cnter += 1 #Keep updating/accumulating

            ##### Check if the current node existed or not #####
            if (record_node in root_child_dict):
                for [next_node, sub_wgt] in root_child_dict[record_node]:
                    next_wgt = (record_wgt + sub_wgt) #Next weight

                    ##### Check if the next weight is smaller or not #####
                    if (edge_rank_arry[next_node] > next_wgt):
                        edge_rank_arry[next_node] = next_wgt #Keep updating/overwriting

                        heappush(record_pq, [next_wgt, next_node]) #Keep updating/recording
                    else:
                        pass
            else:
                pass

        return (max(edge_rank_arry) if (res_cnter == n) else (-1))
