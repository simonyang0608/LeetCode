class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of arrays (i.e. nums, record-nums) #####
        len_nums, len_record_nums = len(nums), (-1)

        ##### Record nums array #####
        record_nums = deepcopy(nums)

        ##### Record stack #####
        record_stack = []

        ##### Result array #####
        res_arry = [(-1) for _ in range(len_nums)]


        ############################
        #Stack-based loop traversal
        ##### Step 1: Record circular indexed-value with array #####
        for nums_idx in range((len_nums - 1)):
            record_nums.append(nums[nums_idx]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        len_record_nums = len(record_nums) #Length of record-nums array

        for record_nums_idx in range(len_record_nums):
            while (record_stack and ((record_nums[record_stack[(-1)]] < record_nums[record_nums_idx]))):

                ##### Check if the current index exceed boundary or not #####
                if (record_stack[(-1)] >= len_nums):
                    record_stack.pop() #Keep updating/popped

                    continue

                res_arry[record_stack.pop()] = record_nums[record_nums_idx] #Keep updating/overwriting

            record_stack.append(record_nums_idx) #Keep updating/recording

        return res_arry
