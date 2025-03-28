class Solution(object):
    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of graph array #####
        len_graph = len(graph)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Edge summary counter array #####
        edge_cnter_arry = [0 for _ in range(len_graph)]

        ##### Record queue #####
        record_queue = []

        ##### Result array #####
        res_arry = []


        ######################################################################
        #Breath-first search based traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes information with dictionary/hashmap #####
        for graph_idx in range(len_graph):
            for next_node in graph[graph_idx]:

                ##### Check if the next node existed or not #####
                if (next_node not in root_child_dict):
                    root_child_dict[next_node] = [graph_idx] #Keep updating/recording
                else:
                    (root_child_dict[next_node]).append(graph_idx) #Keep updating/recording

                edge_cnter_arry[graph_idx] += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for graph_idx in range(len_graph):

            ##### Check if the current summary counter matched conditions or not #####
            if (not edge_cnter_arry[graph_idx]):
                record_queue.append(graph_idx) #Keep updating/recording
            else:
                pass

        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                record_node = record_queue.pop(0) #Record node

                res_arry.append(record_node) #Keep updating/recording

                ##### Check if the current node existed or not #####
                if (record_node in root_child_dict):
                    for next_node in root_child_dict[record_node]:
                        edge_cnter_arry[next_node] -= 1 #Keep updating/reducing

                        ##### Check if the current summary counter matched conditions or not #####
                        if (not edge_cnter_arry[next_node]):
                            record_queue.append(next_node) #Keep updating/recording
                        else:
                            pass
                else:
                    pass

        res_arry.sort() #Sorted-operations

        return res_arry
