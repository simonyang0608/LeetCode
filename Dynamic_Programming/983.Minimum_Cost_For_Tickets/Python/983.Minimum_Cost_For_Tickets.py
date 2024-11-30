class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Maximun of days array #####
        max_days = max(days)
        max_days += 1

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp_arry = [0 for _ in range(max_days)]


        ##########################################
        #Dynamic-programming based loop traversal
        for record_dp_idx in range(1, max_days):

            ##### Check if the current days existed or not #####
            if (record_dp_idx in days):
                record_dp_arry[record_dp_idx] = (record_dp_arry[(record_dp_idx - 1)] + costs[0]) #Keep updating/overwriting

                ##### Check if the current days matched conditions or not #####
                if (record_dp_idx >= 7):
                    record_dp_arry[record_dp_idx] = min(record_dp_arry[record_dp_idx], (record_dp_arry[(record_dp_idx - 7)] + costs[1])) #Keep updating/overwriting
                else:
                    record_dp_arry[record_dp_idx] = min(record_dp_arry[record_dp_idx], (record_dp_arry[0] + costs[1])) #Keep updating/overwriting

                if (record_dp_idx >= 30):
                    record_dp_arry[record_dp_idx] = min(record_dp_arry[record_dp_idx], (record_dp_arry[(record_dp_idx - 30)] + costs[2])) #Keep updating/overwriting
                else:
                    record_dp_arry[record_dp_idx] = min(record_dp_arry[record_dp_idx], (record_dp_arry[0] + costs[2])) #Keep updating/overwriting

            else:
                record_dp_arry[record_dp_idx] = record_dp_arry[(record_dp_idx - 1)] #Keep updating/overwriting

        return record_dp_arry[(max_days - 1)]
