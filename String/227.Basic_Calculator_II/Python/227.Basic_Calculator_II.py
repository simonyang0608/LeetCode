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

        ##### Record operations #####
        record_opr = '+'

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result summary value #####
        res_sum_val = 0


        ############################
        #Stack-based loop traversal
        ##### Step 1: Record indexed-char with stack #####
        while (record_trav_ptr < len_s):

            ##### Check if the current indexed-char is digit or not #####
            if (s[record_trav_ptr] == ' '):
                record_trav_ptr += 1 #Keep updating/traversing

                continue

            if (s[record_trav_ptr].isdigit()):
                record_val = 0 #Record value

                while ((record_trav_ptr < len_s) and (s[record_trav_ptr].isdigit())):
                    record_val = ((10 * record_val) + int(s[record_trav_ptr])) #Keep updating/overwriting

                    record_trav_ptr += 1 #Keep updating/traversing

                record_trav_ptr -= 1 #Keep updating/pre-traverse

                if (record_opr == '+'):
                    record_stack.append(record_val) #Keep updating/recording

                elif (record_opr == '-'):
                    record_stack.append(((-1) * record_val)) #Keep updating/recording

                elif (record_opr == '*'):

                    ##### Check if the current capacity is enough or not #####
                    if (record_stack):
                        prev_val = record_stack.pop() #Previous value

                        prev_val *= record_val #Keep updating/product

                        record_stack.append(prev_val) #Keep updating/recording
                    else:
                        pass

                else:
                    ##### Check if the current capacity is enough or not #####
                    if (record_stack):
                        prev_val = record_stack.pop() #Previous value

                        prev_val /= (record_val + 0.0) #Keep updating/divide

                        record_stack.append(int(prev_val)) #Keep updating/recording
                    else:
                        pass

            elif (s[record_trav_ptr] == '+'):

                ##### Check if the current operations matched conditions or not #####
                if (record_opr != '+'):
                    record_opr = '+' #Update/Overwrite
                else:
                    pass

            elif (s[record_trav_ptr] == '-'):

                ##### Check if the current operations matched conditions or not #####
                if (record_opr != '-'):
                    record_opr = '-' #Update/Overwrite
                else:
                    pass

            elif (s[record_trav_ptr] == '*'):

                ##### Check if the current operations matched conditions or not #####
                if (record_opr != '*'):
                    record_opr = '*' #Update/Overwrite
                else:
                    pass

            else:
                ##### Check if the current operations matched conditions or not #####
                if (record_opr != '/'):
                    record_opr = '/' #Update/Overwrite
                else:
                    pass

            record_trav_ptr += 1 #Keep updating/traversing

        ##### Step 2: Looped-traversal with recorded stack #####
        while (record_stack):
            res_sum_val += record_stack.pop() #Keep updating/accumulating

        return res_sum_val
