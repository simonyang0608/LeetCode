class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of graph array #####
        len_graph = len(graph)

        len_graph -= 1

        ##### Record dictionary/hashmap #####
        record_dict = {graph_idx: [] for graph_idx in range(len_graph)}

        ##### Record array #####
        record_arry = []

        ##### Result array #####
        res_arry = []


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record neighbors node-value with dictionary/hashmap #####
        for graph_idx in range(len_graph):
            for neighbors in graph[graph_idx]:

                (record_dict[graph_idx]).append(neighbors) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        self.dfsTraversal(record_dict, 0, len_graph, record_arry, res_arry) #Recursion fucntion call

        return res_arry


    def dfsTraversal(self, record_dict, record_val, final_val, record_arry, res_arry):
        """
        :type record_dict: dict
        :type record_val: int
        :type final_val: int
        :type record_arry: List[int]
        :type res_arry: List[List[int]]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ####################
        #Whole process/flow
        record_arry.append(record_val) #Update/Record

        ##### Check if the current root node-value matched conditions or not #####
        if (record_val == final_val):
            res_arry.append(record_arry) #Update/Record

            record_arry.pop() #Update/Popped

            return

        for neighbors in record_dict[record_val]:
            self.dfsTraversal(record_dict, neighbors, final_val, record_arry, res_arry) #Recursion function call

        record_arry.pop() #Update/Popped
