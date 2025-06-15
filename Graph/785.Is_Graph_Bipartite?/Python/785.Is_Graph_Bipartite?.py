class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of graph array #####
        len_graph = len(graph)

        ##### Color array #####
        color_arry = [0 for _ in range(len_graph)]

        ##### Record queue #####
        record_queue = []


        ##########################################
        #Breath-first search based loop traversal
        for record_idx in range(len_graph):

            ##### Check if the current node is visited or not #####
            if (color_arry[record_idx]):
                continue

            ##### Check if the whole nodes is bipartite or not #####
            if (not self.is_bipartite(graph, color_arry, record_idx, record_queue)):
                return False

        return True


    def is_bipartite(self, graph, color_arry, record_node, record_queue):
        """
        :type graph: List[List[int]]
        :type color_arry: List[int]
        :type record_node: int
        :type record_queue: List[int]
        :rtype: bool
        """
        #==============================================#
        # Breath-first search based traversal function #
        #==============================================#

        ####################
        #Whole process/flow
        color_arry[record_node] = 1 #Update/Overwrite

        record_queue.append(record_node) #Update/Record

        while (record_queue):
            len_queue = len(record_queue) #Length of record queue

            for queue_idx in range(len_queue):
                curr_node = record_queue.pop(0) #Current node

                for next_node in graph[curr_node]:

                    ##### Check if the next-node is visited or not #####
                    if (not color_arry[next_node]):
                        color_arry[next_node] = (color_arry[curr_node] * (-1)) #Keep updating/overwriting

                        record_queue.append(next_node) #Keep updating/recording
                    else:
                        ##### Check if the whole nodes is bipartite or not #####
                        if (color_arry[next_node] == color_arry[curr_node]):
                            return False

        return True
