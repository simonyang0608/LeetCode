class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        #===================================#
        # Merge-sort based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. nums1, nums2) #####
        len_nums1, len_nums2 = len(nums1), len(nums2)

        ##### Length of total array #####
        len_total = (len_nums1 + len_nums2)

        ##### Record pointers (i.e. nums1, nums2) #####
        record_nums1_ptr, record_nums2_ptr = 0, 0

        ##### Result array #####
        res_arry = []


        #####################################################
        #Merge-sort based loop traversal with recorded array
        ##### Step 1: Looped-traversal for the first intervals #####
        while ((record_nums1_ptr < len_nums1) and (record_nums2_ptr < len_nums2)):

            ##### Check if the current indexed-value is smaller or not #####
            if (nums1[record_nums1_ptr] < nums2[record_nums2_ptr]):
                res_arry.append(nums1[record_nums1_ptr]) #Keep updating/recording

                record_nums1_ptr += 1 #Keep updating/traversing
            else:
                res_arry.append(nums2[record_nums2_ptr]) #Keep updating/recording

                record_nums2_ptr += 1 #Keep updating/traversing

        ##### Step 2: Looped-traversal for the rest remainings #####
        while (record_nums1_ptr < len_nums1):
            res_arry.append(nums1[record_nums1_ptr]) #Keep updating/recording

            record_nums1_ptr += 1 #Keep updating/traversing

        while (record_nums2_ptr < len_nums2):
            res_arry.append(nums2[record_nums2_ptr]) #Keep updating/recording

            record_nums2_ptr += 1 #Keep updating/traversing

        return (((res_arry[(len_total // 2)] + res_arry[((len_total // 2) - 1)]) / 2.) if (not (len_total % 2)) else 
                  res_arry[(len_total // 2)])
