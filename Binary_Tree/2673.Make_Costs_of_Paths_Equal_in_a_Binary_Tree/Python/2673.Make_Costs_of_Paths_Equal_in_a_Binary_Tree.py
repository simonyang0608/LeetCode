class Solution(object):
    def minIncrements(self, n, cost):
        """
        :type n: int
        :type cost: List[int]
        :rtype: int
        """
        #==================================#
        # Recursion based traversal method #
        #==================================#

        ############
        #Initialize
        ##### Result minimun operations #####
        res_min_oprs = [0]

        ################################
        #Recursion based loop traversal
        self.recurseTraversal(((n // 2) - 1), cost, res_min_oprs) #Recursion function call

        return res_min_oprs[0]


    def recurseTraversal(self, record_val_pair_idx, cost, res_min_oprs):
        """
        :type record_val_pair_idx: int
        :type cost: List[int]
        :type res_min_oprs: List[int]
        :rtype: None, void
        """
        #====================================#
        # Recursion based traversal function #
        #====================================#
        if (record_val_pair_idx < 0): #Issue/Boundary-case handling
            return

        res_min_oprs[0] += abs(cost[((record_val_pair_idx << 1) + 1)] - cost[((record_val_pair_idx << 1) + 2)]) #Update/Accumulate
        cost[record_val_pair_idx] += max(cost[((record_val_pair_idx << 1) + 1)] , cost[((record_val_pair_idx << 1) + 2)]) #Update/Accumulate

        self.recurseTraversal((record_val_pair_idx - 1), cost, res_min_oprs) #Recursion function call
