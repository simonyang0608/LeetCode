class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record stack #####
        record_stack = []

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result summary value, sign #####
        res_sum_val, res_sign = 0, 1


        ############################
        #Stack-based loop traversal
        while (record_trav_ptr < len_s):

            ##### Check if the current indexed-char is digit or not #####
            if (s[record_trav_ptr] == ' '):
                record_trav_ptr += 1 #Keep updating/traversing

                continue

            if ((s[record_trav_ptr]).isdigit()):
                record_sum_val = 0 #Record summary value

                while ((record_trav_ptr < len_s) and (s[record_trav_ptr]).isdigit()):
                    record_sum_val = ((10 * record_sum_val) + int(s[record_trav_ptr])) #Record summary value

                    record_trav_ptr += 1 #Keep updating/traversing

                record_trav_ptr -= 1 #Keep updating/pre-traverse

                res_sum_val += (record_sum_val * res_sign) #Keep updating/accumulating

            elif (s[record_trav_ptr] == '+'):

                ##### Check if the current sign matched conditions or not #####
                if (res_sign != 1):
                    res_sign = (+1) ##Keep updating/overwriting
                else:
                    pass

            elif (s[record_trav_ptr] == '-'):

                ##### Check if the current sign matched conditions or not #####
                if (res_sign != (-1)):
                    res_sign = (-1) ##Keep updating/overwriting
                else:
                    pass

            elif (s[record_trav_ptr] == '('):
                record_stack.append(res_sum_val) ##Keep updating/recording
                record_stack.append(res_sign) ##Keep updating/recording

                res_sum_val &= 0 ##Keep updating/reset
                res_sign = 1 ##Keep updating/overwriting

            else:
                ##### Check if the current capacity is enough or not #####
                if (len(record_stack) >= 2):
                    prev_sign = record_stack.pop() ##Keep updating/popped
                    prev_sum_val = record_stack.pop() ##Keep updating/popped

                    res_sum_val *= prev_sign ##Keep updating/product
                    res_sum_val += prev_sum_val ##Keep updating/accumulating

                else:
                    pass

            record_trav_ptr += 1 ##Keep updating/traversing

        return res_sum_val
