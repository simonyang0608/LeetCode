class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ####################################################################
        #Two-pointers based loop traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_s):

            ##### Check if the current indexed-char existed or not #####
            if (s[record_right_ptr] not in record_dict):
                res_max_cnter = max(res_max_cnter, ((record_right_ptr - record_left_ptr) + 1)) #Keep updating/overwriting

                record_dict[s[record_right_ptr]] = True #Keep updating/recording

                record_right_ptr += 1 #Keep updating/traversing

            else:
                res_max_cnter = max(res_max_cnter, (record_right_ptr - record_left_ptr)) #Keep updating/overwriting

                while (record_left_ptr < record_right_ptr):
                    del record_dict[s[record_left_ptr]] #Keep updating/delete

                    record_left_ptr += 1 #Keep updating/traversing

                    ##### Check if the current indexed-char existed or not #####
                    if (s[record_right_ptr] not in record_dict):
                        break
                    else:
                        pass

        return res_max_cnter
