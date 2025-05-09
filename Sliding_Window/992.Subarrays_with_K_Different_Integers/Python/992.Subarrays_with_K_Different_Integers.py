class Solution(object):
    def subarraysWithKDistinct(self, nums, k):
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

        return (self.sldWindow(len_nums, nums, k) - self.sldWindow(len_nums, nums, (k - 1)))


    def sldWindow(self, len_nums, nums, k):
        """
        :type len_nums: int
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #=========================================#
        # Sliding-window based traversal function #
        #=========================================#

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_nums):

            ##### Check if the current indexed-value existed or not #####
            if ((nums[record_right_ptr] not in record_dict) or (not record_dict[nums[record_right_ptr]])):
                record_dict[nums[record_right_ptr]] = 1 #Keep updating/recording

                record_cnter += 1 #Keep updating/accumulating
            else:
                record_dict[nums[record_right_ptr]] += 1 #Keep updating/recording

            while (record_cnter > k):
                record_dict[nums[record_left_ptr]] -= 1 #Keep updating/recording

                ##### Check if the current summary counter matched conditions or not #####
                if (not record_dict[nums[record_left_ptr]]):
                    record_cnter -= 1 #Keep updating/reducing
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            res_max_cnter += (record_right_ptr - record_left_ptr + 1) #Keep updating/accumulating

            record_right_ptr += 1 #Keep updating/traversing

        return res_max_cnter
