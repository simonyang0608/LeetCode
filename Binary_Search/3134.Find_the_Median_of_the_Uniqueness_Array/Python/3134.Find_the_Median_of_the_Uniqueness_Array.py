class Solution(object):
    def medianOfUniquenessArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Total summary counter #####
        total_cnter = ((len_nums * (len_nums + 1)) // 2)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, len_nums

        ##### Record middle index #####
        record_middle_idx = ((total_cnter // 2) if ((total_cnter % 2)) else ((total_cnter // 2) - 1))


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current uniques reached k-th order or not #####
            if (self.uniqueKth(nums, len_nums, record_mid_ptr, record_middle_idx)):
                record_right_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        return record_left_ptr


    def uniqueKth(self, nums, len_nums, record_mid_ptr, record_middle_idx):
        """
        :type nums: List[int]
        :type len_nums: int
        :type record_mid_ptr: int
        :type record_middle_idx: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counter #####
        res_cnter = 0


        ####################
        #Whole process/flow
        while (record_right_ptr < len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[record_right_ptr] not in record_dict):
                record_dict[nums[record_right_ptr]] = 1 #Keep updating/recording
            else:
                record_dict[nums[record_right_ptr]] += 1 #Keep updating/recording

            while (len(record_dict) > record_mid_ptr):
                record_dict[nums[record_left_ptr]] -= 1 #Keep updating/reducing

                ##### Check if the current indexed-value matched conditions or not #####
                if (not record_dict[nums[record_left_ptr]]):
                    del record_dict[nums[record_left_ptr]] #Keep updating/delete
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            res_cnter += ((record_right_ptr - record_left_ptr) + 1) #Keep updating/accumulating

            ##### Check if the current summary counter matched conditions or not #####
            if (res_cnter > record_middle_idx):
                return True

            record_right_ptr += 1 #Keep updating/traversing

        return False
