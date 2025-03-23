class Solution(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of nums arrays (i.e. 1, 2) #####
        len_nums1, len_nums2 = len(nums1), len(nums2)

        ##### Record dictionary/hashmaps (i.e. 1, 2) #####
        record_dict1, record_dict2 = {}, {}

        ##### Result arrays (i.e. 1, 2) #####
        res_arry1, res_arry2 = [], []


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record indexed-value with dictionary/hashmaps #####
        for nums1_idx in range(len_nums1):

            ##### Check if the current indexed-value existed or not #####
            if (nums1[nums1_idx] in record_dict1):
                continue

            record_dict1[nums1[nums1_idx]] = True #Keep updating/recording

        for nums2_idx in range(len_nums2):

            ##### Check if the current indexed-value existed or not #####
            if (nums2[nums2_idx] in record_dict2):
                continue

            record_dict2[nums2[nums2_idx]] = True #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmaps #####
        for record_key in record_dict1:

            ##### Check if the current indexed-value existed or not #####
            if (record_key in record_dict2):
                continue

            res_arry1.append(record_key) #Keep updating/recording

        for record_key in record_dict2:

            ##### Check if the current indexed-value existed or not #####
            if (record_key in record_dict1):
                continue

            res_arry2.append(record_key) #Keep updating/recording

        return [res_arry1, res_arry2]
