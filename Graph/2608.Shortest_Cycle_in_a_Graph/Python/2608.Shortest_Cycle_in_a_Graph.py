class Solution(object):
    def findShortestCycle(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Root-child array #####
        root_child_arry = [[] for _ in range(n)]

        ##### Record queue #####
        record_queue = []

        ##### Result minimun length #####
        res_min_length = [float("inf")]


        ###############################################################
        #Breath-first search based loop traversal with recorded array
        ##### Step 1: Record indexed-nodes informations #####
        for edges_idx in range(len_edges):
            (root_child_arry[(edges[edges_idx])[0]]).append((edges[edges_idx])[1]) #Keep updating/recording
            (root_child_arry[(edges[edges_idx])[1]]).append((edges[edges_idx])[0]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array
        for n_idx in range(n):
            self.bfsTraversal(root_child_arry, n, n_idx, record_queue, res_min_length) #BFS function call

        return ((-1) if (res_min_length[0] == float("inf")) else res_min_length[0])


    def bfsTraversal(self, root_child_arry, n, record_node, record_queue, res_min_length):
        """
        :type root_child_arry: List[List[int]]
        :type n: int
        :type record_node: int
        :type record_queue: List[tuple]
        :type res_min_length: List[int]
        :rtype: None, void
        """
        #==============================================#
        # Breath-first search based traversal function #
        #==============================================#

        ############
        #Initialize
        ##### Length array #####
        length_arry = [(-1) for _ in range(n)]

        #####################
        #Whole proceess/flow
        length_arry[record_node] = 0 #Update/Overwrite

        record_queue.append((record_node, (-1))) #Update/Record

        while (record_queue):
            (curr_node, curr_parent) = record_queue.pop(0) #Keep updating/popped

            for next_node in root_child_arry[curr_node]:

                ##### Check if the next-nodes is visited or not #####
                if (length_arry[next_node] == (-1)):
                    length_arry[next_node] = (length_arry[curr_node] + 1) #Keep updating/overwriting

                    record_queue.append((next_node, curr_node)) #Keep updating/recording
                else:
                    ##### Check if the next-nodes matched conditions or not #####
                    if (next_node != curr_parent):
                        res_min_length[0] = min(res_min_length[0], (length_arry[next_node] + length_arry[curr_node] + 1)) #Keep updating/overwriting
                    else:
                        pass

        return
