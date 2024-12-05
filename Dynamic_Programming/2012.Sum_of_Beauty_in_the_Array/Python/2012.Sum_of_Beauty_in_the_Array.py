class Solution(object):
    def sumOfBeauties(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming array (i.e. prefix, suffix) #####
        record_prefix_dp_arry, record_suffix_dp_arry = [0 for _ in range(len_nums)], [0 for _ in range(len_nums)]

        record_prefix_dp_arry[0] = (-1)
        record_prefix_dp_arry[1] = nums[0]

        record_suffix_dp_arry[(len_nums - 1)] = (1e5 + 1)
        record_suffix_dp_arry[(len_nums - 2)] = nums[(len_nums - 1)]

        ##### Result summary value #####
        res_sum_val = 0


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        ##### Step 1: Record indexed-value with dynamic-programming array (i.e. prefix, suffix) #####
        for nums_idx in range(2, len_nums): #Prefix
            record_prefix_dp_arry[nums_idx] += max(record_prefix_dp_arry[(nums_idx - 1)], nums[(nums_idx - 1)]) #Keep updating/overwriting

        for nums_idx in range((len_nums - 3), (-1), (-1)): #Suffix
            record_suffix_dp_arry[nums_idx] += min(record_suffix_dp_arry[(nums_idx + 1)], nums[(nums_idx + 1)]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dynamic-programming array (i.e. prefix, suffix) #####
        for record_idx in range(1, (len_nums - 1)):

            ##### Check if the current indexed-value matched conditions or not #####
            if ((nums[record_idx] > record_prefix_dp_arry[record_idx]) and (nums[record_idx] < record_suffix_dp_arry[record_idx])):
                res_sum_val += 2 #Keep updating/accumulating

            elif ((nums[record_idx] > nums[(record_idx - 1)]) and (nums[record_idx] < nums[(record_idx + 1)])):
                res_sum_val += 1 #Keep updating/accumulating

            else:
                pass

        return res_sum_val
