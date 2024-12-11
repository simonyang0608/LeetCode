class Solution(object):
    def isArraySpecial(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of arraies (i.e. nums, queries) #####
        len_nums, len_queries = len(nums), len(queries)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp_arry = [0 for _ in range(len_nums)]

        ##### Record char #####
        record_char = ("o" if ((nums[0] % 2)) else "e")

        ##### Result array #####
        res_arry = [False for _ in range(len_queries)]


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        ##### Step 1: Record indexed-value with Dynamic-programming (i.e. DP) array #####
        for nums_idx in range(1, len_nums):

            ##### Check if the current indexed-char matched conditions or not #####
            if (record_char == "o"):

                ##### Check if the current indexed-value matched conditions or not #####
                if (not (nums[nums_idx] % 2)):
                    record_dp_arry[nums_idx] = (record_dp_arry[(nums_idx - 1)] + 1) #Keep updating/overwriting

                    record_char = "e" #Keep updating/overwriting
                else:
                    record_dp_arry[nums_idx] = record_dp_arry[(nums_idx - 1)] #Keep updating/overwriting

            else:
                ##### Check if the current indexed-value matched conditions or not #####
                if ((nums[nums_idx] % 2)):
                    record_dp_arry[nums_idx] = (record_dp_arry[(nums_idx - 1)] + 1) #Keep updating/overwriting

                    record_char = "o" #Keep updating/overwriting
                else:
                    record_dp_arry[nums_idx] = record_dp_arry[(nums_idx - 1)] #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded Dynamic-programming (i.e. DP) array #####
        for queries_idx in range(len_queries):
            record_query_lidx, record_query_ridx = (queries[queries_idx])[0], (queries[queries_idx])[1]  #Record query indexes (i.e. left, right)

            ##### Check if the current difference matched conditions or not #####
            if ((record_query_ridx - record_query_lidx) != (record_dp_arry[record_query_ridx] - record_dp_arry[record_query_lidx])):
                pass
            else:
                res_arry[queries_idx] = True #Keep updating/overwriting

        return res_arry
