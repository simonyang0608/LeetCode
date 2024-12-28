class Solution(object):
    def maximumCostSubstring(self, s, chars, vals):
        """
        :type s: str
        :type chars: str
        :type vals: List[int]
        :rtype: int
        """
        #=================================#
        # Kadane's-based traversal method #
        #=================================#

        ############
        #Initialize
        ##### Length of strings (i.e. s, chars) #####
        len_s, len_chars = len(s), len(chars)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record maximun costs #####
        record_max_cost = 0

        ##### Result maximun costs #####
        res_max_cost = ((-1) * (10 ** 9))


        ################################################################
        #Kadane's-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-char with dictionary/hashmap #####
        for chars_idx in range(len_chars):
            record_dict[chars[chars_idx]] = vals[chars_idx] #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for s_idx in range(len_s):

            ##### Check if the current indexed-char existed or not #####
            if (s[s_idx] in record_dict):
                record_max_cost += record_dict[s[s_idx]] #Keep updating/accumulating
            else:
                record_max_cost += (ord(s[s_idx]) - 96) #Keep updating/accumulating

            res_max_cost = max(res_max_cost, record_max_cost) #Keep updating/overwriting

            ##### Check if the current costs needs to be reset or not #####
            if (record_max_cost < 0):
                record_max_cost &= 0 #Keep updating/reset
            else:
                pass

        return (0 if (res_max_cost < 0) else res_max_cost)
