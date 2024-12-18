class Solution(object):
    def findNumberOfLIS(self, nums):
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

        ##### Record array (i.e. dynamic-programming, counter) #####
        record_dp, record_cnter = [1 for _ in range(len_nums)], [1 for _ in range(len_nums)]

        ##### Result summary counter #####
        res_cnter = 0


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        ##### Step 1: Looped-traversal with dynamic-programming array #####
        for record_right_ptr in range(1, len_nums):
            for record_left_ptr in range(record_right_ptr):

                ##### Check if the current indexed-value matched conditions or not #####
                if (nums[record_right_ptr] > nums[record_left_ptr]):

                    ##### Check if the current length is larger or not #####
                    if ((record_dp[record_left_ptr] + 1) > record_dp[record_right_ptr]):
                        record_dp[record_right_ptr] = (record_dp[record_left_ptr] + 1) #Keep updating/overwriting

                        record_cnter[record_right_ptr] = record_cnter[record_left_ptr] #Keep updating/overwriting
                    elif ((record_dp[record_left_ptr] + 1) == record_dp[record_right_ptr]):
                        record_cnter[record_right_ptr] += record_cnter[record_left_ptr] #Keep updating/accumulating
                    else:
                        pass
                else:
                    pass

        ##### Step 2: Post-process/Final completions #####
        record_max_val = max(record_dp) #Record maximun value

        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not ##### 
            if (record_dp[nums_idx] == record_max_val):
                res_cnter += record_cnter[nums_idx] #Keep updating/accumulating
            else:
                pass

        return res_cnter
