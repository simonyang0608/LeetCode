class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of temperatures array #####
        len_temperatures = len(temperatures)

        ##### Record stack #####
        record_stack = []

        ##### Result array #####
        res_arry = [0 for _ in range(len_temperatures)]


        ############################
        #Stack-based loop traversal
        for temperatures_idx in range(len_temperatures):
            while (record_stack and ((record_stack[(-1)])[0] < temperatures[temperatures_idx])):
                res_arry[(record_stack[(-1)])[1]] = (temperatures_idx - (record_stack[(-1)])[1]) #Keep updating/overwriting

                record_stack.pop() #Keep updating/popped

            record_stack.append((temperatures[temperatures_idx], temperatures_idx)) #Keep updating/recording

        return res_arry
