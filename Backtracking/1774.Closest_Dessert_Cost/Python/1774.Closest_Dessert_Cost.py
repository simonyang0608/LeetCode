class Solution(object):
    def closestCost(self, baseCosts, toppingCosts, target):
        """
        :type baseCosts: List[int]
        :type toppingCosts: List[int]
        :type target: int
        :rtype: int
        """
        #============================================#
        # Recursion-based backtrack traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. baseCosts, toppingCosts) #####
        len_baseCosts, len_toppingCosts = len(baseCosts), len(toppingCosts)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record minimun differences #####
        record_min_diff = [(10 ** 6)]

        ##### Result minimun differences #####
        res_min_diff = [(10 ** 6)]


        ###########################################################################
        #Recursion-based backtrack loop traversal with recorded dictionary/hashmap
        for record_idx in range(len_baseCosts):
            self.recurseTraversal(toppingCosts, len_toppingCosts, target, 0, baseCosts[record_idx], record_min_diff, record_dict) #Recursion function call

            res_min_diff[0] = min(res_min_diff[0], record_min_diff[0]) #Keep updating/overwriting

            record_min_diff[0] = (10 ** 6) #Keep updating/overwriting

        (record_dict[res_min_diff[0]]).sort() #Sorted operations

        return (record_dict[res_min_diff[0]])[0]


    def recurseTraversal(self, toppingCosts, len_toppingCosts, target, record_idx, record_cost, record_min_diff, record_dict):
        """
        :type toppingCosts: List[int]
        :type target: int
        :type record_idx: int
        :type record_cost: int
        :type record_min_diff: List[int]
        :type record_dict: dict
        :rtype: None, void
        """
        #==============================================#
        # Recursion-based backtrack traversal function #
        #==============================================#
        if (record_idx >= len_toppingCosts): #Issue/Boundary-case handling

            ##### Check if the current differences is smaller or not #####
            if (abs(target - record_cost) <= record_min_diff[0]):
                record_min_diff[0] = abs(target - record_cost) #Update/Overwrite

                ##### Check if the current differences existed or not #####
                if (record_min_diff[0] not in record_dict):
                    record_dict[record_min_diff[0]] = [record_cost] #Update/Record
                else:
                    (record_dict[record_min_diff[0]]).append(record_cost) #Update/Record

            return

        self.recurseTraversal(toppingCosts, len_toppingCosts, target, (record_idx + 1), record_cost, record_min_diff, record_dict) #Recursion function call (i.e. no get)
        self.recurseTraversal(toppingCosts, len_toppingCosts, target, (record_idx + 1), (record_cost + toppingCosts[record_idx]), record_min_diff, record_dict) #Recursion function call (i.e. get once)
        self.recurseTraversal(toppingCosts, len_toppingCosts, target, (record_idx + 1), (record_cost + (toppingCosts[record_idx] * 2)), record_min_diff, record_dict) #Recursion function call (i.e. get twice)
