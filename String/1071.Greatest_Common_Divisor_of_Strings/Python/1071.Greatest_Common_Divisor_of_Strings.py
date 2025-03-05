class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        #=================================#
        # Math-GCD based traversal method #
        #=================================#

        ############
        #Initialize
        ##### Length of strings (i.e. str1, str2) #####
        len_str1, len_str2 = len(str1), len(str2)

        ##### Result string #####
        res_str = ""


        ###############################
        #Math-GCD based loop traversal
        for record_idx in range(1, (len_str1 + 1)):

            ##### Check if the current length is a common-dividor or not #####
            if ((len_str1 % record_idx) or (len_str2 % record_idx)):
                continue

            record_str = str1[: record_idx] #Record string

            target_str1, target_str2 = "", "" #Target strings (i.e. str1, str2)
        
            for _ in range((len_str1 // record_idx)):
                target_str1 += record_str #Keep updating/recording

            ##### Check if the current target string matched conditions or not #####
            if (target_str1 != str1):
                continue

            for _ in range((len_str2 // record_idx)):
                target_str2 += record_str #Keep updating/recording

            ##### Check if the current target string matched conditions or not #####
            if (target_str2 != str2):
                continue

            res_str = record_str #Keep updating/overwriting

        return res_str
