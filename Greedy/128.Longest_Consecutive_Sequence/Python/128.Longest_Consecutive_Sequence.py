class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        if (not len_nums): #Issue/Boundary-case handling
            return 0

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 1


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] not in record_dict):
                record_dict[nums[nums_idx]] = True #Keep updating/recording
            else:
                pass

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_dict[nums[nums_idx]]):

                ##### Check if the current indexed-value existed or not #####
                if ((nums[nums_idx] - 1) not in record_dict):
                    while ((nums[nums_idx] in record_dict) and (record_dict[nums[nums_idx]])):
                        record_cnter += 1 #Keep updating/accumulating

                        record_dict[nums[nums_idx]] = False #Keep updating/recording

                        nums[nums_idx] += 1 #Keep updating/accumulating

                    res_max_cnter = max(res_max_cnter, record_cnter) #Keep updating/overwriting

                    ##### Check if the current summary counter needs to be reset or not #####
                    if (record_cnter):
                        record_cnter = 0 #Keep updating/reset
                    else:
                        pass
                else:
                    pass
            else:
                pass

        return res_max_cnter
