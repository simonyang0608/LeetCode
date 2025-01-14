class Solution(object):
    def smallestDistancePair(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (max(nums) - min(nums))


        ####################################
        #Binary-search based loop traversal
        nums.sort() #Sorted operations

        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current distance matched conditions or not #####
            if (self.distKth(nums, len_nums, k, record_mid_ptr)):
                record_right_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        return record_left_ptr


    def distKth(self, nums, len_nums, k, record_val):
        """
        :type nums: List[int]
        :type len_nums: int
        :type k: int
        :type record_val: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 1

        ##### Record summary counter #####
        record_cnter = 0


        ####################
        #Whole process/flow
        while (record_right_ptr < len_nums):

            ##### Check if the current distance difference matched conditions or not #####
            if ((nums[record_right_ptr] - nums[record_left_ptr]) <= record_val):
                pass
            else:
                while ((record_left_ptr < record_right_ptr) and ((nums[record_right_ptr] - nums[record_left_ptr]) > record_val)):
                    record_left_ptr += 1 #Keep updating/traversing
            
            record_cnter += (record_right_ptr - record_left_ptr) #Keep updating/accumulating

            ##### Check if the current summary counter exceeds k-th order or not #####
            if (record_cnter >= k):
                return True

            record_right_ptr += 1 #Keep updating/traversing

        return False
