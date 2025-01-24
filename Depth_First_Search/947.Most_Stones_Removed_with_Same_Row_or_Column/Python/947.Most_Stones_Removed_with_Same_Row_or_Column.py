class Solution(object):
    def removeStones(self, stones):
        """
        :type stones: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of stones array #####
        len_stones = len(stones)

        ##### Record visited dictionary/hashmap #####
        record_dict_visited = {}

        ##### Result minimun summary counter #####
        res_min_cnter = 0


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        for stones_idx in range(len_stones):

            ##### Check if the current index is visited or not #####
            if (stones_idx in record_dict_visited):
                continue
            
            self.dfsTraversal(stones, len_stones, record_dict_visited, stones_idx) #Recursion function call

            res_min_cnter += 1 #Keep updating/accumulating

        return (len_stones - res_min_cnter)


    def dfsTraversal(self, stones, len_stones, record_dict_visited, record_idx):
        """
        :type stones: List[List[int]]
        :type len_stones: int
        :type record_dict_visited: dict
        :type record_idx: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ####################
        #Whole process/flow
        record_dict_visited[record_idx] = True #Update/Record

        for stones_idx in range(len_stones):

            ##### Check if the current index is visited or not #####
            if (stones_idx in record_dict_visited):
                continue

            ##### Check if the current rows or columns is shared or not #####
            if (((stones[record_idx])[0] == (stones[stones_idx])[0]) or ((stones[stones_idx])[1] == (stones[record_idx])[1])):
                self.dfsTraversal(stones, len_stones, record_dict_visited, stones_idx) #Recursion function call
