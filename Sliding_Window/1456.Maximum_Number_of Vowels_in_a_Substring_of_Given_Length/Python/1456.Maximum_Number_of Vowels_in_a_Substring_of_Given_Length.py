class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record dictionary/hashmap #####
        record_dict = {'a': True, 'e': True, 'i': True, 'o': True, 'u': True}

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        #####################################
        #Sliding-window based loop traversal
        ##### Step 1: Looped-traversal for the first fixed-window size #####
        for s_idx in range(k):
            record_cnter += (1 if (s[s_idx] in record_dict) else 0) #Keep updating/accumulating

        ##### Step 2: Looped-traversal for the remainings #####
        res_max_cnter = max(res_max_cnter, record_cnter) #Update/Overwrite

        for s_idx in range(k, len_s):
            record_cnter -= (1 if (s[(s_idx - k)] in record_dict) else 0) #Keep updating/reducing

            record_cnter += (1 if (s[s_idx] in record_dict) else 0) #Keep updating/accumulating

            res_max_cnter = max(res_max_cnter, record_cnter) #Keep updating/overwriting

        return res_max_cnter
