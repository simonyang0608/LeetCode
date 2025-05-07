class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[int]
        :rtype: str
        """
        #=======================================#
        # Prefix-summary based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Result string #####
        res_str = ""


        #####################################
        #Prefix-summary based loop traversal
        ##### Step 1: Record prefix-summary informations with array #####
        for record_idx in range((len_s - 2), (-1), (-1)):
            shifts[record_idx] += shifts[(record_idx + 1)] #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded prefix-summary array #####
        for record_idx in range(len_s):
            res_str += chr(((((ord(s[record_idx]) - 97) + shifts[record_idx]) % 26) + 97)) #Keep updating/recording

        return res_str
