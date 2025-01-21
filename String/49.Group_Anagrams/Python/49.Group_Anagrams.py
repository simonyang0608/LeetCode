class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of strs array #####
        len_strs = len(strs)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result array #####
        res_arry = []


        ##################################################
        #Hashmap-based loop traversal with recorded array
        ##### Step 1: Record indexed-string with dictionary/hashmap #####
        for strs_idx in range(len_strs):
            record_str = strs[strs_idx] #Record string

            record_arry = [0 for _ in range(26)] #Record array

            res_str = "" #Result string

            for record_chr in record_str:
                record_arry[(ord(record_chr) - 97)] += 1 #Keep updating/recording

            for record_idx in range(26):

                ##### Check if the current indexed-char existed or not #####
                if (record_arry[record_idx]):
                    res_str += (chr((record_idx + 97)) + str(record_arry[record_idx])) #Keep updating/recording
                else:
                    pass

            ##### Check if the current indexed-string existed or not #####
            if (res_str not in record_dict):
                record_dict[res_str] = [record_str] #Keep updating/recording
            else:
                (record_dict[res_str]).append(record_str) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_key in record_dict:
            res_arry.append(record_dict[record_key]) #Keep updating/recording

        return res_arry
