class Solution(object):
    def maxSatisfaction(self, satisfaction):
        """
        :type satisfaction: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of satisfaction array #####
        len_satisfaction = len(satisfaction)

        ##### Record traversal pointer, times #####
        record_trav_ptr, record_times = (-1), 1

        ##### Result maximun summary value #####
        res_max_sum = 0


        #############################
        #Greedy-based loop traversal
        ##### Step 1: Looped-traversal for the first summary value #####
        satisfaction.sort() #Sorted operations

        for satisfaction_idx in range(len_satisfaction):

            ##### Check if the current indexed-value matched conditions or not #####
            if (satisfaction[satisfaction_idx] < 0):
                continue

            ##### Check if the current index is recorded or not
            if (record_trav_ptr == (-1)):
                record_trav_ptr = satisfaction_idx #Keep updating/overwriting
            else:
                pass

            res_max_sum += (satisfaction[satisfaction_idx] * record_times) #Keep updating/accumulating

            record_times += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal for the remainings #####
        if (not res_max_sum): #Issue/Boundary-case handling
            return 0

        for satisfaction_idx in range((record_trav_ptr - 1), (-1), (-1)):
            curr_sum_val = self.BoundSum(len_satisfaction, satisfaction, satisfaction_idx) #Current summary value

            res_max_sum = max(res_max_sum, curr_sum_val) #Keep updating/overwriting

        return res_max_sum


    def BoundSum(self, len_satisfaction, satisfaction, record_val):
        """
        :type len_satisfaction: int
        :type satisfaction: List[int]
        :type record_val: int
        :rtype: int
        """

        ############
        #Initialize
        ##### Record times #####
        record_times = 1

        ##### Result summary value #####
        res_sum_val = 0


        ####################
        #Whole process/flow
        for satisfaction_idx in range(record_val, len_satisfaction):
            res_sum_val += (satisfaction[satisfaction_idx] * record_times) #Keep updating/accumulating

            record_times += 1 #Keep updating/accumulating

        return res_sum_val
