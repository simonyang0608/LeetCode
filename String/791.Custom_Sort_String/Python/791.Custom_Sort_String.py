class Solution(object):
    def customSortString(self, order, s):
        """
        :type order: str
        :type s: str
        :rtype: str
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of strings (i.e. order, s) #####
        len_order, len_s = len(order), len(s)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result string #####
        res_str = ""


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record indexed-char with dictionary/hashmap #####
        for s_idx in range(len_s):

            ##### Check if the current indexed-char existed or not #####
            if (s[s_idx] not in record_dict):
                record_dict[s[s_idx]] = 1 #Keep updating/recording
            else:
                record_dict[s[s_idx]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal for the recorded dictionary/hashmap #####
        for order_idx in range(len_order):

            ##### Check if the current indexed-char existed or not #####
            if (order[order_idx] not in record_dict):
                continue

            while (record_dict[order[order_idx]] > 0):
                res_str += order[order_idx] #Keep updating/recording

                record_dict[order[order_idx]] -= 1 #Keep updating/reducing

        for record_key in record_dict:

            ##### Check if the current summary counter matched conditions or not #####
            if (record_dict[record_key] <= 0):
                continue

            while (record_dict[record_key] > 0):
                res_str += record_key #Keep updating/recording

                record_dict[record_key] -= 1 #Keep updating/reducing

        return res_str
