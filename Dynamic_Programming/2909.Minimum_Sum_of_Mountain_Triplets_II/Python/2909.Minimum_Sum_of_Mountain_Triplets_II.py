class Solution(object):
    def minimumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming array (i.e. prefix, suffix) #####
        record_dp_prefix_arry, record_dp_suffix_arry = [0 for _ in range(len_nums)], [0 for _ in range(len_nums)]

        record_dp_prefix_arry[0], record_dp_prefix_arry[1] = (1e8 + 1), nums[0]
        record_dp_suffix_arry[(len_nums - 1)], record_dp_suffix_arry[(len_nums - 2)] = (1e8 + 1), nums[(len_nums - 1)]

        ##### Result minimun summary value #####
        res_min_sum = (3e8 + 1)


        ##########################################
        #Dynamic-programming based loop traversal
        ##### Step 1: Record indexed-value with dynamic-programming array (i.e. prefix, suffix) #####
        for nums_idx in range(2, len_nums): #Prefix
            record_dp_prefix_arry[nums_idx] += min(record_dp_prefix_arry[(nums_idx - 1)], nums[nums_idx - 1]) #Keep updating/overwriting

        for nums_idx in range((len_nums - 3), (-1), (-1)): #Suffix
            record_dp_suffix_arry[nums_idx] += min(record_dp_suffix_arry[(nums_idx + 1)], nums[(nums_idx + 1)]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dynamic-programming array (i.e. prefix, suffix) #####
        for record_idx in range(1, (len_nums - 1)):
            record_pivot = nums[record_idx] #Record pivot

            ##### Check if the current indexed-value matched conditions or not #####
            if ((record_dp_prefix_arry[record_idx] >= record_pivot) or (record_dp_suffix_arry[record_idx] >= record_pivot)):
                continue
            
            res_min_sum = min(res_min_sum, (record_pivot + record_dp_prefix_arry[record_idx] + record_dp_suffix_arry[record_idx])) #Keep updating/overwriting

        return ((-1) if (res_min_sum == (3e8 + 1)) else res_min_sum)
