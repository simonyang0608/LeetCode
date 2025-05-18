class Solution(object):
    def closestMeetingNode(self, edges, node1, node2):
        """
        :type edges: List[int]
        :type node1: int
        :type node2: int
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Lenght of edges array #####
        len_edges = len(edges)

        ##### Record queue #####
        record_queue = []

        ##### Dist arrays (i.e. 1, 2) #####
        dist1_arry, dist2_arry = [1e9 for _ in range(len_edges)], [1e9 for _ in range(len_edges)]

        ##### Record minimun distance #####
        record_min_dist = 1e9

        ##### Result node index #####
        res_node_idx = (-1)


        ###############################################################
        #Breath-first search based loop traversal with recorded arrays
        ##### Step 1: Record indexed-nodes informations with arrays #####
        self.bfsTraversal(len_edges, edges, record_queue, node1, dist1_arry) #BFS function call
        self.bfsTraversal(len_edges, edges, record_queue, node2, dist2_arry) #BFS function call

        ##### Step 2: Looped-traversal with recorded arrays #####
        for edges_idx in range(len_edges):
            curr_max_dist = max(dist1_arry[edges_idx], dist2_arry[edges_idx]) #Current maximun distance

            ##### Check if the current distance matched conditions or not #####
            if (curr_max_dist < record_min_dist):
                record_min_dist = curr_max_dist #Keep updating/overwriting

                res_node_idx = edges_idx #Keep updating/overwriting
            else:
                pass

        return res_node_idx


    def bfsTraversal(self, len_edges, edges, record_queue, record_node, dist_arry):
        """
        :type len_edges: int
        :type edges: List[int]
        :type record_queue: List[int]
        :type record_node: int
        :type dist_arry: List[int]
        :rtype: None, void
        """
        #==============================================#
        # Breath-first search based traversal function #
        #==============================================#

        ############
        #Initialize
        ##### Visit array #####
        visit_arry = [False for _ in range(len_edges)]

        ####################
        #Whole process/flow
        record_queue.append(record_node) #Update/Record

        visit_arry[record_node] = True #Update/Overwrite

        dist_arry[record_node] = 0 #Update/Overwrite

        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                curr_node = record_queue.pop(0) #Current node

                ##### Check if the next node existed or not #####
                if (edges[curr_node] == (-1)):
                    continue

                ##### Check if the next node is visited or not #####
                if (visit_arry[edges[curr_node]]):
                    continue

                visit_arry[edges[curr_node]] = True #Keep updating/overwriting

                dist_arry[edges[curr_node]] = (dist_arry[curr_node] + 1) #Keep updating/overwriting

                record_queue.append(edges[curr_node]) #Keep updating/recording            
