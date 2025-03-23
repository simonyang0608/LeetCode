class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record dictionary/hashmaps (i.e. summary counter) #####
        record_dict, record_dict_cnter = {}, {}


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for arr_idx in range(len_arr):

            ##### Check if the current indexed-value existed or not #####
            if (arr[arr_idx] not in record_dict):
                record_dict[arr[arr_idx]] = 1 #Keep updating/recording
            else:
                record_dict[arr[arr_idx]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_key in record_dict:

            ##### Check if the current summary counter existed or not #####
            if (record_dict[record_key] not in record_dict_cnter):
                record_dict_cnter[record_dict[record_key]] = 1 #Keep updating/recording
            else:
                return False

        return True
