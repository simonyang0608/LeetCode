class Solution(object):
    def shortestAlternatingPaths(self, n, redEdges, blueEdges):
        """
        :type n: int
        :type redEdges: List[List[int]]
        :type blueEdges: List[List[int]]
        :rtype: List[int]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. red, blue-edges) #####
        len_redEdges, len_blueEdges = len(redEdges), len(blueEdges)

        ##### Root-child array #####
        root_child_arry = [[] for _ in range(n)]

        ##### Visit array #####
        visit_arry = [[False, False] for _ in range(n)]

        ##### Record queue #####
        record_queue = []

        ##### Record steps #####
        record_steps = 0

        ##### Result array #####
        res_arry = [(-1) for _ in range(n)]


        ###############################################################
        #Breath-first search based loop traversal with recorded arrays
        ##### Step 1: Record indexed-nodes informations with arrays #####
        for redEdges_idx in range(len_redEdges):
            (root_child_arry[(redEdges[redEdges_idx])[0]]).append(((redEdges[redEdges_idx])[1], 'r')) #Keep updating/recording

        for blueEdges_idx in range(len_blueEdges):
            (root_child_arry[(blueEdges[blueEdges_idx])[0]]).append(((blueEdges[blueEdges_idx])[1], 'b')) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded arrays #####
        record_queue.append((0, 'n')) #Update/Record

        res_arry[0] = record_steps #Update/Overwrite

        while (record_queue):
            len_queue = len(record_queue) #Length of record queue

            for queue_idx in range(len_queue):
                (curr_node, curr_chr) = record_queue.pop(0) #Current node, char

                for (next_node, next_chr) in root_child_arry[curr_node]:

                    ##### Check if the current char matched conditions or not #####
                    if (curr_chr == next_chr):
                        continue

                    next_idx = (0 if (next_chr == 'r') else 1) #Next color index

                    ##### Check if the next color index is visited or not #####
                    if ((visit_arry[next_node])[next_idx]):
                        continue

                    (visit_arry[next_node])[next_idx] = True #Keep updating/overwriting

                    ##### Check if the next-node steps matched conditions or not #####
                    if (res_arry[next_node] == (-1)):
                        res_arry[next_node] = (record_steps + 1) #Keep updating/overwriting
                    else:
                        pass

                    record_queue.append((next_node, next_chr)) #Keep updating/recording
        
            record_steps += 1 #Keep updating/traversing

        return res_arry
