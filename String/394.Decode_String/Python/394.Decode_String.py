class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record stacks (i.e. value, string) #####
        record_stack_val, record_stack_str = [], []

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record value #####
        record_val = 0

        ##### Result string #####
        res_str = ""


        ############################
        #Stack-based loop traversal
        while (record_trav_ptr < len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[record_trav_ptr] == '['):
                record_stack_val.append(record_val) #Keep updating/recording

                ##### Check if the current value needs to be reset or not #####
                if (record_val):
                    record_val &= 0 #Keep updating/reset
                else:
                    pass

                record_stack_str.append(res_str) #Keep updating/recording

                ##### Check if the current string needs to be reset or not #####
                if (res_str):
                    res_str = "" #Keep updating/reset
                else:
                    pass

                record_trav_ptr += 1 #Keep updating/traversing
            
            elif (s[record_trav_ptr] == ']'):
                record_str = record_stack_str.pop() #Record string

                record_times = record_stack_val.pop() #Record times

                for times_idx in range(record_times):
                    record_str += res_str #Keep updating/recording

                res_str = record_str #Keep updating/overwriting

                record_trav_ptr += 1 #Keep updating/traversing

            else:
                ##### Check if the current indexed-char is-digit or not #####
                if (s[record_trav_ptr].isdigit()):
                    while ((record_trav_ptr < len_s) and (s[record_trav_ptr].isdigit())):
                        record_val = ((10 * record_val) + int(s[record_trav_ptr])) #Keep updating/overwriting

                        record_trav_ptr += 1 #Keep updating/traversing
                else:
                    while ((record_trav_ptr < len_s) and (s[record_trav_ptr].isalpha())):
                        res_str += s[record_trav_ptr] #Keep updating/recording

                        record_trav_ptr += 1 #Keep updating/traversing

        return res_str
