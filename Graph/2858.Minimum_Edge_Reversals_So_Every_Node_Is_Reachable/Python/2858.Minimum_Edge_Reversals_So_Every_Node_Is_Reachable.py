class Solution(object):
    def minEdgeReversals(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Record queue #####
        record_queue = []

        ##### Result array #####
        res_arry = [0 for _ in range(n)]


        ###########################################################################
        #Breath-first search based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for edges_idx in range(len_edges):
            curr_node, next_node = (edges[edges_idx])[0], (edges[edges_idx])[1] #Current, Next nodes

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [(next_node, 1)] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append((next_node, 1)) #Keep updating/recording
            
            ##### Check if the next node existed or not #####
            if (next_node not in root_child_dict):
                root_child_dict[next_node] = [(curr_node, (-1))] #Keep updating/recording
            else:
                (root_child_dict[next_node]).append((curr_node, (-1))) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        self.bfs_prev(root_child_dict, record_queue, res_arry, n) #BFS function call (i.e. previous step)

        self.bfs_post(root_child_dict, record_queue, res_arry, n) #BFS function call (i.e. post-final step)

        return res_arry


    def bfs_prev(self, root_child_dict, record_queue, res_arry, n):
        """
        :type root_child_dict: dict
        :type record_queue: List[int]
        :type res_arry: List[int]
        :type n: int
        :rtype: None, void
        """
        #==============================================#
        # Breath-first search based traversal function #
        #==============================================#

        ############
        #Initialize
        ##### Visit array #####
        visit_arry = [False for _ in range(n)]

        ####################
        #Whole process/flow
        record_queue.append(0) #Update/Record

        visit_arry[0] = True #Update/Overwrite

        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                record_node = record_queue.pop(0) #Record node

                ##### Check if the current node existed or not #####
                if (record_node in root_child_dict):
                    for (next_node, next_scl) in root_child_dict[record_node]:

                        ##### Check if the current node is visited or not #####
                        if (visit_arry[next_node]):
                            continue

                        visit_arry[next_node] = True #Keep updating/overwriting

                        res_arry[0] += (1 if (next_scl < 0) else 0) #Keep updating/accumulating

                        record_queue.append(next_node) #Keep updating/recording
                else:
                    pass

        return


    def bfs_post(self, root_child_dict, record_queue, res_arry, n):
        """
        :type root_child_dict: dict
        :type record_queue: List[int]
        :type res_arry: List[int]
        :type n: int
        :rtype: None, void
        """
        #==============================================#
        # Breath-first search based traversal function #
        #==============================================#

        ############
        #Initialize
        ##### Visit array #####
        visit_arry = [False for _ in range(n)]

        ####################
        #Whole process/flow
        record_queue.append(0) #Update/Record

        visit_arry[0] = True #Update/Overwrite

        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                record_node = record_queue.pop(0) #Record node

                ##### Check if the current node existed or not #####
                if (record_node in root_child_dict):
                    for (next_node, next_scl) in root_child_dict[record_node]:

                        ##### Check if the current node is visited or not #####
                        if (visit_arry[next_node]):
                            continue

                        visit_arry[next_node] = True #Keep updating/overwriting

                        res_arry[next_node] = (res_arry[record_node] + (1 if (next_scl > 0) else (-1))) #Keep updating/overwriting

                        record_queue.append(next_node) #Keep updating/recording
                else:
                    pass

        return
