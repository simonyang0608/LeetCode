class Solution(object):
    def maximumRobots(self, chargeTimes, runningCosts, budget):
        """
        :type chargeTimes: List[int]
        :type runningCosts: List[int]
        :type budget: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of chargeTimes array #####
        len_chargeTimes = len(chargeTimes)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, len_chargeTimes


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) // 2) #Record middle pointer

            record_flag = self.kthBudget(len_chargeTimes, chargeTimes, runningCosts, budget, record_mid_ptr) #Record flag

            ##### Check if the current window-size exceed boundary or not #####
            if (not record_flag):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = record_mid_ptr #Keep updating/overwriting

        return record_left_ptr


    def kthBudget(self, len_chargeTimes, chargeTimes, runningCosts, budget, record_val):
        """
        :type len_chargeTimes: int
        :type chargeTimes: List[int]
        :type runningCosts: List[int]
        :type budget: int
        :type record_val: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Record deque #####
        record_dq = []

        ##### Result summary value #####
        res_sum_val = 0


        ####################
        #Whole process/flow
        ##### Step 1: Looped-traversal for the first fixed-window size #####
        for chargeTimes_idx in range(record_val):
            while (record_dq and ((record_dq[(-1)])[0] < chargeTimes[chargeTimes_idx])):
                record_dq.pop() #Keep updating/popped

            record_dq.append((chargeTimes[chargeTimes_idx], chargeTimes_idx)) #Keep updating/recording

            res_sum_val += runningCosts[chargeTimes_idx] #Keep updating/accumulating

        ##### Step 2: Looped-traversal for the remainings #####
        if (((record_dq[0])[0] + (record_val * res_sum_val)) <= budget): #Issue/Boundary-case handling
            return True

        for chargeTimes_idx in range(record_val, len_chargeTimes):
            res_sum_val -= runningCosts[(chargeTimes_idx - record_val)] #Keep updating/reducing

            ##### Check if previous index exceed prev-window size or not /////
            if ((record_dq[0])[1] <= (chargeTimes_idx - record_val)):
                record_dq.pop(0) #Keep updating/popped
            else:
                pass

            while (record_dq and ((record_dq[(-1)])[0] < chargeTimes[chargeTimes_idx])):
                record_dq.pop() #Keep updating/popped

            record_dq.append((chargeTimes[chargeTimes_idx], chargeTimes_idx)) #Keep updating/recording

            res_sum_val += runningCosts[chargeTimes_idx] #Keep updating/accumulating

            if (((record_dq[0])[0] + (record_val * res_sum_val)) <= budget): #Issue/Boundary-case handling
                return True

        return False
