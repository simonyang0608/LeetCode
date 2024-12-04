class Solution(object):
    def maximumTripletValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming-based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming array (i.e. prefix, suffix) #####
        record_prefix_dp_arry, record_suffix_dp_arry = [0 for _ in range(len_nums)], [0 for _ in range(len_nums)]

        record_prefix_dp_arry[0] = (-1)
        record_prefix_dp_arry[1] = nums[0]

        record_suffix_dp_arry[(len_nums - 1)] = (-1)
        record_suffix_dp_arry[(len_nums - 2)] = nums[(len_nums - 1)]

        ##### Result maximun product #####
        res_max_prod = 0


        ##########################################
        #Dynamic-programming-based loop traversal
        ##### Step 1: Record indexed-value with dynamic-programming array (i.e. prefix, suffix) #####
        for nums_idx in range(2, len_nums): #Prefix
            record_prefix_dp_arry[nums_idx] += max(record_prefix_dp_arry[(nums_idx - 1)], nums[(nums_idx - 1)]) #Keep updating/overwriting

        for nums_idx in range((len_nums - 3), (-1), (-1)): #Suffix
            record_suffix_dp_arry[nums_idx] += max(record_suffix_dp_arry[(nums_idx + 1)], nums[(nums_idx + 1)])

        ##### Step 2: Looped-traversal with recorded dynamic-programming array (i.e. prefix, suffix) #####
        for record_idx in range(1, (len_nums - 1)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[record_idx] >= record_prefix_dp_arry[record_idx]):
                continue

            res_max_prod = max(res_max_prod, ((record_prefix_dp_arry[record_idx] - nums[record_idx]) * record_suffix_dp_arry[record_idx])) #Keep updating/overwriting

        return (0 if (not res_max_prod) else res_max_prod)
