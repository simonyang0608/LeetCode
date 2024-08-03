class Solution(object):
    def longestCommonPrefix(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of arrs (i.e. arr1, arr2) array #####
        len_arr1, len_arr2 = len(arr1), len(arr2)

        ##### Record dictionary/hashmaps (i.e. arr1, arr2) #####
        record_dict_arr1, record_dict_arr2 = {}, {}

        ##### Record string #####
        record_str = ""

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for arr1_idx in range(len_arr1):
            curr_str = str(arr1[arr1_idx]) #Current indexed-string
            len_str = len(curr_str) #Length of indexed-string

            for str_idx in range(len_str):
                record_str += curr_str[str_idx] #Keep updating/recording

                ##### Check if the current indexed-string existed or not #####
                if (record_str not in record_dict_arr1):
                    record_dict_arr1[record_str] = True #Keep updating/recording
                else:
                    pass

            record_str = "" #Reset

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for arr2_idx in range(len_arr2):
            curr_str = str(arr2[arr2_idx]) #Current indexed-string
            len_str = len(curr_str) #Length of indexed-string

            for str_idx in range(len_str):
                record_str += curr_str[str_idx] #Keep updating/recording

                ##### Check if the current indexed-string existed or not #####
                if (record_str in record_dict_arr1):

                    ##### Check if the current indexed-string existed or not #####
                    if (record_str not in record_dict_arr2):
                        res_max_cnter = max(res_max_cnter, len(record_str)) #Keep updating/overwriting

                        record_dict_arr2[record_str] = True #Keep updating/recording
                    else:
                        pass

                else:
                    pass

            record_str = "" #Reset

        return res_max_cnter
