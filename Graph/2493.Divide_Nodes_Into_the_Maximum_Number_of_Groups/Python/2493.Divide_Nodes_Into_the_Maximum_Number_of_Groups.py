class Solution(object):
    def magnificentSets(self, n, edges):
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

        ##### Result array #####
        res_arry = [0 for _ in range(n)]


        ##############################################################
        #Breath-first search based loop traversal with recorded array
        ##### Step 1: Record indexed-nodes informations with array #####
        for edges_idx in range(len_edges):
            (root_child_arry[((edges[edges_idx])[0] - 1)]).append(((edges[edges_idx])[1] - 1)) #Keep updating/recording
            (root_child_arry[((edges[edges_idx])[1] - 1)]).append(((edges[edges_idx])[0] - 1)) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        for n_idx in range(n):

            ##### Check if the current group status matched conditions or not #####
            if (not self.bfsTraversal(root_child_arry, n, n_idx, record_queue, res_arry)):
                return (-1)

        return sum(res_arry)


    def bfsTraversal(self, root_child_arry, n, record_node, record_queue, res_arry):
        """
        :type root_child_arry: List[List[int]]
        :type n: int
        :type record_node: int
        :type record_queue: List[int]
        :type res_arry: List[int]
        :rtype: bool
        """
        #==============================================#
        # Breath-first search based traversal function #
        #==============================================#

        ############
        #Initialize
        ##### Group array #####
        gp_arry = [0 for _ in range(n)]

        ##### Base node #####
        base_node = record_node

        ##### Maximun groups #####
        max_group = 1


        ####################
        #Whole process/flow
        gp_arry[record_node] = 1 #Update/Overwrite
 
        record_queue.append(record_node) #Update/Record

        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                curr_node = record_queue.pop(0) #Keep updating/popped

                base_node = min(base_node, curr_node) #Keep updating/overwriting

                for next_node in root_child_arry[curr_node]:

                    ##### Check if the next node is visited or not #####
                    if (not gp_arry[next_node]):
                        gp_arry[next_node] = (gp_arry[curr_node] + 1) #Keep updating/overwriting

                        max_group = max(max_group, gp_arry[next_node]) #Keep updating/overwriting

                        record_queue.append(next_node) #Keep updating/recording
                    else:
                        ##### Check if the current group status matched conditions or not #####
                        if (abs(gp_arry[next_node] - gp_arry[curr_node]) != 1):
                            return False

        res_arry[base_node] = max(res_arry[base_node], max_group) #Update/Overwrite

        return True
