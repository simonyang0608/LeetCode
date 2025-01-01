class Solution(object):
    def countSubTrees(self, n, edges, labels):
        """
        :type n: int
        :type edges: List[List[int]]
        :type labels: str
        :rtype: List[int]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record value #####
        record_val = 0

        ##### Visit array #####
        visit_arry = [0 for _ in range(n)]

        ##### Result array #####
        res_arry = [0 for _ in range(n)]


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        for edges_idx in range(len_edges):

            ##### Check if the current indexed-value existed or not #####
            if ((edges[edges_idx])[0] not in record_dict):
                record_dict[(edges[edges_idx])[0]] = [(edges[edges_idx])[1]] #Keep updating/recording
            else:
                (record_dict[(edges[edges_idx])[0]]).append((edges[edges_idx])[1]) #Keep updating/recording

            if ((edges[edges_idx])[1] not in record_dict):
                record_dict[(edges[edges_idx])[1]] = [(edges[edges_idx])[0]] #Keep updating/recording
            else:
                (record_dict[(edges[edges_idx])[1]]).append((edges[edges_idx])[0]) #Keep updating/recording

        char_arry = self.dfsTraversal(record_dict, record_val, labels, visit_arry, res_arry) #Recursion function call

        return res_arry

        
    def dfsTraversal(self, record_dict, record_val, labels, visit_arry, res_arry):
        """
        :type record_dict: dict
        :type record_val: int
        :type labels: str
        :type visit_arry: List[int]
        :type res_arry: List[int]
        :rtype: List[int]
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ############
        #Initialize
        ##### Char array #####
        char_arry = [0 for _ in range(26)]

        ####################
        #Whole process/flow
        if (not visit_arry[record_val]):
            visit_arry[record_val] = 1 #Update/Overwrite

            char_arry[(ord(labels[record_val]) - 97)] += 1 #Update/Accumulate

            if (record_val in record_dict):
                for next_val in record_dict[record_val]:
                    record_char_arry = self.dfsTraversal(record_dict, next_val, labels, visit_arry, res_arry) #Recursion function call

                    for record_idx in range(26):
                        char_arry[record_idx] += record_char_arry[record_idx] #Keep updating/accumulating

            res_arry[record_val] += char_arry[(ord(labels[record_val]) - 97)] #Keep updating/accumulating

        return char_arry
