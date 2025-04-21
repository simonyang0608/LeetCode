class Solution(object):
    def numberOfPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. nums1, nums2) #####
        len_nums1, len_nums2 = len(nums1), len(nums2)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counter #####
        res_cnter = 0


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record indexed-value informations with dictionary/hashmap #####
        for nums1_idx in range(len_nums1):
            record_val = nums1[nums1_idx] #Record value

            for record_idx in range(1, (record_val + 1)):

                ##### Check if the current square exceed boundary or not #####
                if ((record_idx ** 2) > record_val):
                    break

                record_squr = (record_idx ** 2) #Record square

                ##### Check if the current square matched conditions or not #####
                if (record_squr == record_val):

                    ##### Check if the current indexed-value existed or not #####
                    if (record_idx not in record_dict):
                        record_dict[record_idx] = 1 #Keep updating/recording
                    else:
                        record_dict[record_idx] += 1 #Keep updating/recording

                elif (not (record_val % record_idx)):

                    ##### Check if the current indexed-value existed or not #####
                    if ((record_val // record_idx) not in record_dict):
                        record_dict[(record_val // record_idx)] = 1 #Keep updating/recording
                    else:
                        record_dict[(record_val // record_idx)] += 1 #Keep updating/recording

                    ##### Check if the current indexed-value existed or not #####
                    if (record_idx not in record_dict):
                        record_dict[record_idx] = 1 #Keep updating/recording
                    else:
                        record_dict[record_idx] += 1 #Keep updating/recording
                else:
                    pass

        ##### Step 2: Looped-traversal for the recorded dictionary/hashmap #####
        for nums2_idx in range(len_nums2):
            record_prod = (nums2[nums2_idx] * k) #Record product value

            ##### Check if the current product existed or not #####
            if (record_prod in record_dict):
                res_cnter += record_dict[record_prod] #Keep updating/accumulating
            else:
                pass

        return res_cnter
