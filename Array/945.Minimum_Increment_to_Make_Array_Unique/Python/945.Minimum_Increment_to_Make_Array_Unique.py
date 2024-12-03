class Solution(object):
    def minIncrementForUnique(self, nums):
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

        ##### Sorted operations #####
        nums.sort()

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record maximun value #####
        record_max_val = (-1)

        ##### Result minimun summary counter #####
        res_min_cnter = 0


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] not in record_dict):
                record_dict[nums[nums_idx]] = True #Keep updating/recording

                record_max_val = nums[nums_idx] #Keep updating/overwriting

            else:
                record_max_val += 1 #Keep updating/accumulating

                res_min_cnter += (record_max_val - nums[nums_idx]) #Keep updating/accumulating

                record_dict[record_max_val] = True #Keep updating/recording

        return res_min_cnter
