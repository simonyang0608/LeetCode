class Solution(object):
    def maximumSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record summary value #####
        record_sum_val = 0

        ##### Result maximun summary value #####
        res_max_sum = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[record_right_ptr] not in record_dict):
                record_sum_val += nums[record_right_ptr] #Keep updating/accumulating

                record_dict[nums[record_right_ptr]] = 1 #Keep updating/recording

                ##### Check if the current length matched conditions or not #####
                if (len(record_dict) > k):
                    record_sum_val -= nums[record_left_ptr] #Keep updating/reducing

                    del record_dict[nums[record_left_ptr]] #Keep updating/delete

                    record_left_ptr += 1 #Keep updating/delete

                else:
                    pass

                ##### Check if the current length matched conditions or not #####
                if (len(record_dict) == k):
                    res_max_sum = max(res_max_sum, record_sum_val) #Keep updating/overwriting
                else:
                    pass

                record_right_ptr += 1 #Keep updating/traversing

            else:
                while (nums[record_right_ptr] in record_dict):
                    record_sum_val -= nums[record_left_ptr] #Keep updating/reducing

                    del record_dict[nums[record_left_ptr]] #Keep updating/delete

                    record_left_ptr += 1 #Keep updating/traversing

        return res_max_sum
