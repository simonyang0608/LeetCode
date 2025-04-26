class Solution(object):
    def findTheCity(self, n, edges, distanceThreshold):
        """
        :type n: int
        :type edges: List[List[int]]
        :type distanceThreshold: int
        :rtype: int
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

        ##### Result minimun summary counter, maximun node #####
        res_min_cnter, res_max_node = float("inf"), (-1)

        
        ##################################################################
        #Dijkstras' based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for edges_idx in range(len_edges):
            curr_node, next_node = (edges[edges_idx])[0], (edges[edges_idx])[1] #Current, Next nodes

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [(next_node, (edges[edges_idx])[2])] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append((next_node, (edges[edges_idx])[2])) #Keep updating/recording

            ##### Check if the next node existed or not #####
            if (next_node not in root_child_dict):
                root_child_dict[next_node] = [(curr_node, (edges[edges_idx])[2])] #Keep updating/recording
            else:
                (root_child_dict[next_node]).append((curr_node, (edges[edges_idx])[2])) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for n_idx in range(n):
            record_cnter = self.dijkstra(root_child_dict, n_idx, distanceThreshold, n) #Record summary counter

            ##### Check if the current summary counter matched conditions or not #####
            if (record_cnter <= res_min_cnter):
                res_min_cnter = record_cnter #Keep updating/overwriting

                res_max_node = n_idx #Keep updating/overwriting
            else:
                pass

        return res_max_node


    def dijkstra(self, root_child_dict, record_node, distanceThreshold, n):
        """
        :type root_child_dict: dict
        :type record_node: int
        :type distanceThreshold: int
        :type n: int
        :rtype: int
        """

        ############
        #Initialize
        ##### Edge rank array #####
        edge_rank_arry = [float("inf") for _ in range(n)]

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Result summary counter #####
        res_cnter = 0


        ####################
        #Whole process/flow
        heapify(record_pq) #Update/Heapify

        heappush(record_pq, (0, record_node)) #Update/Heappush

        edge_rank_arry[record_node] = 0 #Update/Record

        while (record_pq):
            (curr_dist, curr_node) = record_pq[0] #Current distance, node

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current node information matched conditions or not #####
            if (curr_dist != edge_rank_arry[curr_node]):
                continue

            ##### Check if the current node existed or not #####
            if (curr_node in root_child_dict):
                for (next_node, sub_dist) in root_child_dict[curr_node]:
                    next_dist = (curr_dist + sub_dist) #Next distance

                    ##### Check if the next node informations matched conditions or not #####
                    if (edge_rank_arry[next_node] > next_dist):
                        edge_rank_arry[next_node] = next_dist #Keep updating/recording

                        heappush(record_pq, (next_dist, next_node)) #Keep updating/recording
                    else:
                        pass
            else:
                pass

        for n_idx in range(n):

            ##### Check if the current node matched conditions or not #####
            if (n_idx == record_node):
                continue

            ##### Check if the current node informations matched conditions or not #####
            if (edge_rank_arry[n_idx] <= distanceThreshold):
                res_cnter += 1 #Keep updating/accumulating
            else:
                pass

        return res_cnter
