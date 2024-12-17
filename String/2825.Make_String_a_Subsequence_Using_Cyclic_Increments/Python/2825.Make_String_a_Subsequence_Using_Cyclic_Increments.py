class Solution(object):
    def canMakeSubsequence(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: bool
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of strings (i.e. str1, str2) #####
        len_str1, len_str2 = len(str1), len(str2)

        ##### Record pointers (i.e. str1. str2) #####
        record_str1_ptr, record_str2_ptr = 0, 0


        ###################################
        #Two-pointers based loop traversal
        while ((record_str1_ptr < len_str1) and (record_str2_ptr < len_str2)):

            ##### Check if the current indexed-char matched conditions or not #####
            if (((ord(str1[record_str1_ptr]) - 97) == (ord(str2[record_str2_ptr]) - 97)) or ((((ord(str1[record_str1_ptr]) - 97) + 1) % 26) == (ord(str2[record_str2_ptr]) - 97))):
                record_str2_ptr += 1 #Keep updating/traversing
            else:
                pass

            record_str1_ptr += 1 #Keep updating/traversing

        return (True if (record_str2_ptr >= len_str2) else False)
