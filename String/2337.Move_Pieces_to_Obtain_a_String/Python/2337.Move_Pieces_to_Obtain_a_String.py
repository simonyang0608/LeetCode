class Solution(object):
    def canChange(self, start, target): 
        """
        :type start: str
        :type target: str
        :rtype: bool
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of strings (i.e. start, target) #####
        len_string = len(start)

        ##### Record stacks (i.e. left, right) #####
        record_left_stack, record_right_stack = [], []


        ############################
        #Stack-based loop traversal
        for string_idx in range(len_string):

            ##### Check if the current indexed-char matched conditions or not #####
            if (target[string_idx] == 'L'):
                record_left_stack.append('L') #Keep updating/recording
            else:
                pass

            ##### Check if the current stack is empty or not #####
            if (record_left_stack):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((target[string_idx] == 'R') or (start[string_idx] == 'R')):
                    return False
                elif (start[string_idx] == 'L'):
                    record_left_stack.pop() #Keep updating/popped
                else:
                    pass
            else:
                ##### Check if the current indexed-char matched conditions or not #####
                if (start[string_idx] == 'L'):
                    return False
                else:
                    pass

        for string_idx in range((len_string - 1), (-1), (-1)):

            ##### Check if the current indexed-char matched conditions or not #####
            if (target[string_idx] == 'R'):
                record_right_stack.append('R') #Keep updating/recording
            else:
                pass

            ##### Check if the current stack is empty or not #####
            if (record_right_stack):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((target[string_idx] == 'L') or (start[string_idx] == 'L')):
                    return False
                elif (start[string_idx] == 'R'):
                    record_right_stack.pop() #Keep updating/popped
                else:
                    pass
            else:
                ##### Check if the current indexed-char matched conditions or not #####
                if (start[string_idx] == 'R'):
                    return False
                else:
                    pass

        return (False if ((record_left_stack or record_right_stack)) else True)
