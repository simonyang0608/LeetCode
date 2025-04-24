class Solution(object):
    def characterReplacement(self, s, k):
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
        record_dict = {}

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record maximun summary counter #####
        record_max_cnter = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_s):

            ##### Check if the current indexed-char existed or not #####
            if (s[record_right_ptr] not in record_dict):
                record_dict[s[record_right_ptr]] = 1 #Keep updating/recording
            else:
                record_dict[s[record_right_ptr]] += 1 #Keep updating/recording

            record_max_cnter = max(record_max_cnter, record_dict[s[record_right_ptr]]) #Keep updating/overwriting

            ##### Check if the current length matched conditions or not #####
            if (((record_right_ptr - record_left_ptr + 1) - record_max_cnter) > k):
                record_dict[s[record_left_ptr]] -= 1 #Keep updating/recording

                record_left_ptr += 1 #Keep updating/traversing
            else:
                pass

            res_max_cnter = max(res_max_cnter, (record_right_ptr - record_left_ptr + 1)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

        return res_max_cnter
