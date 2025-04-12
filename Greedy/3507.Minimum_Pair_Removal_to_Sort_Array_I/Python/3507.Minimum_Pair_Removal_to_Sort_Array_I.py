class Solution(object):
    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Result minimun steps #####
        res_min_steps = 0


        #############################
        #Greedy-based loop traversal
        while (not self.is_sorted(nums, len_nums)):
            record_idx, record_pair_sum = (-1), float("inf") #Record index, pair-summary

            record_flag = False #Record flag

            for nums_idx in range((len_nums - 1)):

                ##### Check if the current pair-summary matched conditions or not #####
                if ((nums[nums_idx] + nums[(nums_idx + 1)]) < record_pair_sum):
                    record_pair_sum = (nums[nums_idx] + nums[(nums_idx + 1)]) #Keep updating/overwriting

                    record_idx = nums_idx #Keep updating/overwriting
                else:
                    pass

            for nums_idx in range((len_nums - 1)):

                ##### Check if the current flag matched conditions or not #####
                if (not record_flag):

                    ##### Check if the current index matched conditions or not #####
                    if (nums_idx == record_idx):
                        nums[nums_idx] += nums[(nums_idx + 1)] #Keep updating/accumulating

                        record_flag |= True #Keep updating/overwriting
                    else:
                        pass
                else:
                    nums[nums_idx] = nums[(nums_idx + 1)] #Keep updating/overwriting

            res_min_steps += 1 #Keep updating/accumulating

            nums.pop() #Keep updating/popped

            len_nums -= 1 #Keep updating/reducing

        return res_min_steps


    def is_sorted(self, nums, len_nums):
        """
        :type nums: List[int]
        :type len_nums: int
        :rtype: bool
        """

        #####################
        #Whole process/flow
        for nums_idx in range((len_nums - 1)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[nums_idx] > nums[(nums_idx + 1)]):
                return False

        return True
