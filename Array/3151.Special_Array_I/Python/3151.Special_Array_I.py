class Solution(object):
    def isArraySpecial(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #========================================#
        # One-pass update based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        len_nums -= 1


        ######################################
        #One-pass update based loop traversal
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if ((nums[nums_idx] % 2)):

                ##### Check if the next indexed-value matched conditions or not #####
                if (not (nums[(nums_idx + 1)] % 2)):
                    pass
                else:
                    return False
            
            else:
                ##### Check if the next indexed-value matched conditions or not #####
                if ((nums[(nums_idx + 1)] % 2)):
                    pass
                else:
                    return False

        return True
