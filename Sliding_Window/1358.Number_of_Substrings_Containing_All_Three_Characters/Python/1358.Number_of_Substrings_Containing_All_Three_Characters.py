class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
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
        record_dict = {}

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result summary counter #####
        res_cnter = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_s):

            ##### Check if the current indexed-char existed or not #####
            if (s[record_right_ptr] not in record_dict):
                record_dict[s[record_right_ptr]] = 1 #Keep updating/recording
            else:
                record_dict[s[record_right_ptr]] += 1 #Keep updating/recording

            ##### Check if the current size matched conditions or not #####
            if (len(record_dict) >= 3):
                while (len(record_dict) >= 3):
                    record_dict[s[record_left_ptr]] -= 1 #Keep updating/reducing

                    ##### Check if the current key needs to be delete or not #####
                    if (not record_dict[s[record_left_ptr]]):
                        del record_dict[s[record_left_ptr]] #Keep updating/delete
                    else:
                        pass

                    record_left_ptr += 1 #Keep updating/traversing
            else:
                pass

            res_cnter += record_left_ptr #Keep updating/accumulating

            record_right_ptr += 1 #Keep updating/traversing

        return res_cnter
