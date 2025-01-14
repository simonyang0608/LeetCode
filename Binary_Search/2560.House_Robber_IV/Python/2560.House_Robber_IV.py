class Solution(object):
    def minCapability(self, nums, k):
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
        record_left_ptr, record_right_ptr = 0, (len_nums - 1)

        ##### Sorted nums array #####
        sort_nums = sorted(nums)
        

        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current stealed houses exceeds k-th or not #####
            if (self.robKth(len_nums, nums, sort_nums[record_mid_ptr], k)):
                record_right_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        return sort_nums[record_left_ptr]


    def robKth(self, len_nums, nums, record_val, k):
        """
        :type len_nums: int
        :type nums: List[int]
        :type record_val: int
        :type k: int
        :rtype: bool
        """
        
        ############
        #Initialize
        ##### Record traversal pointer, summary counter #####
        record_trav_ptr, record_cnter = 0, 0

        ####################
        #Whole process/flow
        while (record_trav_ptr < len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[record_trav_ptr] <= record_val):
                record_cnter += 1 #Keep updating/accumulating

                record_trav_ptr += 2 #Keep updating/traversing
            else:
                record_trav_ptr += 1 #Keep updating/traversing

        return (True if (record_cnter >= k) else False)
