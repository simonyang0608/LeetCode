class Solution(object):
    def totalSteps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record stack #####
        record_stack = []

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ############################
        #Stack-based loop traversal
        for nums_idx in range((len_nums - 1), (-1), (-1)):
            record_cnter = 0 #Record summary counter

            while (record_stack and ((record_stack[(-1)])[0] < nums[nums_idx])):
                record_cnter = max((record_cnter + 1), (record_stack[(-1)])[1]) #Keep updating/overwriting

                record_stack.pop() #Keep updating/popped

            res_max_cnter = max(res_max_cnter, record_cnter) #Keep updating/overwriting

            record_stack.append([nums[nums_idx], record_cnter]) #Keep updating/recording

        return res_max_cnter
