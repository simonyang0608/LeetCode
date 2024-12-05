class Solution(object):
    def partitionDisjoint(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#
        if (len(nums) == 2): #Issue/Boundary-case handling
            return 1

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming array (i.e. prefix, suffix) #####
        record_prefix_dp_arry, record_suffix_dp_arry = [0 for _ in range(len_nums)], [0 for _ in range(len_nums)]

        record_prefix_dp_arry[0] = (-1)
        record_prefix_dp_arry[1] = nums[0]

        record_suffix_dp_arry[(len_nums - 1)] = (1e6 + 1)
        record_suffix_dp_arry[(len_nums - 2)] = nums[(len_nums - 1)]


        ##########################################
        #Dynamic-programming based loop traversal
        ##### Step 1: Record indexed-value with dynamic-programming array (i.e. prefix, suffix) #####
        for nums_idx in range(2, len_nums): #Prefix
            record_prefix_dp_arry[nums_idx] = max(record_prefix_dp_arry[(nums_idx - 1)], nums[(nums_idx - 1)]) #Keep updating/overwriting

        for nums_idx in range((len_nums - 3), (-1), (-1)): #Suffix
            record_suffix_dp_arry[nums_idx] = min(record_suffix_dp_arry[(nums_idx + 1)], nums[(nums_idx + 1)]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dynamic-programming array (i.e. prefix, suffix) #####
        for record_idx in range(1, len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if ((nums[record_idx] >= record_prefix_dp_arry[record_idx]) and (record_suffix_dp_arry[record_idx] >= record_prefix_dp_arry[record_idx])):
                return record_idx

        return (-1)
