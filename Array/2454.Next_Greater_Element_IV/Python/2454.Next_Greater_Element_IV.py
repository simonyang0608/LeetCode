class Solution(object):
    def secondGreaterElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record stacks (i.e. 1, 2) #####
        record_stack1, record_stack2 = [], []

        ##### Result array #####
        res_arry = [(-1) for _ in range(len_nums)]


        ############################
        #Stack-based loop traversal
        for nums_idx in range(len_nums):
            while (record_stack2 and (nums[record_stack2[(-1)]] < nums[nums_idx])):
                res_arry[record_stack2.pop()] = nums[nums_idx] #Keep updating/overwriting

            record_arry = [] #Record array

            while (record_stack1 and ((nums[record_stack1[(-1)]] < nums[nums_idx]))):
                record_arry.append(record_stack1.pop()) #Keep updating/recording

            ##### Check if the current array is empty or not #####
            if (record_arry):
                for record_idx in record_arry[:: (-1)]:
                    record_stack2.append(record_idx) #Keep updating/recording
            else:
                pass

            record_stack1.append(nums_idx) #Keep updating/recording

        return res_arry
