class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of tokens array #####
        len_tokens = len(tokens)

        ##### Record stack #####
        record_stack = [tokens[0]]

        ##### Record token #####
        record_token = "+-*/"

        ##### Result summary value #####
        res_sum_val = int(tokens[0])


        ############################
        #Stack-based loop traversal
        for tokens_idx in range(1, len_tokens):

            ##### Check if the current indexed-string matched conditions or not #####
            if (tokens[tokens_idx] not in record_token):
                record_stack.append(tokens[tokens_idx]) #Keep updating/recording
            else:
                ##### Check if the current length/size is enough or not #####
                if (len(record_stack) >= 2):
                    record_scnd_val = float(record_stack.pop()) #Record second value
                    record_fst_val = float(record_stack.pop()) #Record first value

                    ##### Check if the current indexed-string matched conditions or not #####
                    if (tokens[tokens_idx] == "+"):
                        res_sum_val = int((record_fst_val + record_scnd_val)) #Keep updating/overwriting
                    elif (tokens[tokens_idx] == "-"):
                        res_sum_val = int((record_fst_val - record_scnd_val)) #Keep updating/overwriting
                    elif (tokens[tokens_idx] == "*"):
                        res_sum_val = int((record_fst_val * record_scnd_val)) #Keep updating/overwriting
                    else:
                        res_sum_val = int((record_fst_val / record_scnd_val)) #Keep updating/overwriting

                    record_stack.append(str(res_sum_val)) #Keep updating/recording
                else:
                    pass

        return res_sum_val
