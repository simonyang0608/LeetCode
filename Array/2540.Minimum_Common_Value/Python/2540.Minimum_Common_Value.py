class Solution(object):
    def getCommon(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array (i.e. nums1, nums2) #####
        len_nums1, len_nums2 = len(nums1), len(nums2)

        ##### Record two-pointers (i.e. nums1, nums2) #####
        record_nums1_ptr, record_nums2_ptr = 0, 0


        ###################################
        #Two-pointers based loop traversal
        while ((record_nums1_ptr < len_nums1) and (record_nums2_ptr < len_nums2)):
            record_nums1_val = nums1[record_nums1_ptr] #Record nums1 value
            record_nums2_val = nums2[record_nums2_ptr] #Record nums2 value

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_nums1_val < record_nums2_val):
                record_nums1_ptr += 1 #Keep updating/accumulating

            elif (record_nums1_val == record_nums2_val):

                return record_nums1_val

            else:
                record_nums2_ptr += 1 #Keep updating/accumulating

        return (-1)
