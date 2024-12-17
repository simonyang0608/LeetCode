class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#
        if (n == 1): #Issue/Boundary-case handling
            return [0]

        if (n == 2): #Issue/Boundary-case handling
            return [0, 1]

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Record array #####
        record_arry = [0 for _ in range(n)]

        ##### Record dictionary/hashmap #####
        record_dict = {}

        for edges_idx in range(len_edges):
            if ((edges[edges_idx])[0] not in record_dict):
                record_dict[(edges[edges_idx])[0]] = [(edges[edges_idx])[1]]
            else:
                (record_dict[(edges[edges_idx])[0]]).append((edges[edges_idx])[1])

            if ((edges[edges_idx])[1] not in record_dict):
                record_dict[(edges[edges_idx])[1]] = [(edges[edges_idx])[0]]
            else:
                (record_dict[(edges[edges_idx])[1]]).append((edges[edges_idx])[0])

            record_arry[(edges[edges_idx])[0]] += 1
            record_arry[(edges[edges_idx])[1]] += 1

        ##### Record queue #####
        record_queue = []

        ##### Result array #####
        res_arry = []


        #################################################
        #Greedy-based loop traversal with recorded queue
        ##### Step 1: Record indexed-value with queue #####
        for n_idx in range(n):

            ##### Check if the current root is external or not #####
            if (record_arry[n_idx] == 1):
                record_queue.append(n_idx) #Keep updating/recording
            else:
                pass

        ##### Step 2: Looped-traversal with recorded queue #####
        while (n > 2):
            record_length = len(record_queue) #Record length

            n -= record_length #Update/Reduce

            for _ in range(record_length):
                record_frontval = record_queue.pop(0) #Record front-value

                for record_val in record_dict[record_frontval]:

                    ##### Check if the current indexed-value matched conditions or not #####
                    if (record_arry[record_val] == 1):
                        continue

                    record_arry[record_val] -= 1 #Keep updating/reducing

                    if (record_arry[record_val] == 1):
                        record_queue.append(record_val) #Keep updating/recording
                    else:
                        pass

        ##### Step 3: Post-process/Final completions #####
        while (record_queue):
            res_arry.append(record_queue.pop(0)) #Keep updating/recording

        return res_arry
