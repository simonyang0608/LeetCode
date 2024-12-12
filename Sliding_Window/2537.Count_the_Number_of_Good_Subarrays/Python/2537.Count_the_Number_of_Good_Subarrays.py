class Solution(object):
    def countGood(self, nums, k):
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

        ##### Record summary counter #####
        record_pair_cnter = 0

        ##### Result summary counter #####
        res_cnter = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[record_right_ptr] not in record_dict):
                record_dict[nums[record_right_ptr]] = 0 #Keep updating/recording
            else:
                pass

            record_pair_cnter += record_dict[nums[record_right_ptr]] #Keep updating/accumulating

            record_dict[nums[record_right_ptr]] += 1 #Keep updating/accumulating

            while ((record_left_ptr < record_right_ptr) and (record_pair_cnter >= k)):
                record_dict[nums[record_left_ptr]] -= 1 #Keep updating/reducing

                record_pair_cnter -= record_dict[nums[record_left_ptr]] #Keep updating/reducing

                record_left_ptr += 1 #Keep updating/traversing

            res_cnter += record_left_ptr #Keep updating/accumulating

            record_right_ptr += 1 #Keep updating/traversing

        return res_cnter
