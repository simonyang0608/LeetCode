class Solution(object):
    def maxDistance(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of nums1 array #####
        len_nums1 = len(nums1)

        ##### Result maximun distance #####
        res_max_dist = [0]


        ####################################
        #Binary-search based loop traversal
        for nums1_idx in range(len_nums1):
            self.binarySearch(nums2, nums1[nums1_idx], nums1_idx, res_max_dist) #Binary-search function call

        return res_max_dist[0]


    def binarySearch(self, nums2, record_val, record_idx, res_max_dist):
        """
        :type nums2: List[int]
        :type record_val: int
        :type record_idx: int
        :type res_max_dist: List[int]
        :rtype: None, void
        """

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(nums2) - 1)

        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if thhe current indexed-value matched conditions or not #####
            if (nums2[record_mid_ptr] >= record_val):

                ##### Check if the current index exceed boundary or not #####
                if (record_mid_ptr >= record_idx):
                    res_max_dist[0] = max(res_max_dist[0], (record_mid_ptr - record_idx)) #Keep updating/overwriting
                else:
                    pass

                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
