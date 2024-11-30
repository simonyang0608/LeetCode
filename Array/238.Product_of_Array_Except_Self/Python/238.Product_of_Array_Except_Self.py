class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #===============================================#
        # Prefix, Suffix-product based traversal method #
        #===============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record array (i.e. prefix, suffix) #####
        record_prefix_arry, record_suffix_arry = deepcopy(nums), deepcopy(nums)

        ##### Result array #####
        res_arry = [0 for _ in range(len_nums)]


        #############################################
        #Prefix, Suffix-product based loop traversal
        ##### Step 1: Record prefix, suffix-product value with array #####
        for nums_idx in range(1, len_nums):
            record_prefix_arry[nums_idx] *= record_prefix_arry[(nums_idx - 1)] #Keep updating/overwriting
            record_suffix_arry[((len_nums - 1) - nums_idx)] *= record_suffix_arry[len_nums - nums_idx] #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded array #####
        record_prefix_arry.insert(0, 1) #Update/Insert
        record_suffix_arry.append(1) #Update/Append

        for record_idx in range(len_nums):
            res_arry[record_idx] += (record_prefix_arry[record_idx] * record_suffix_arry[(record_idx + 1)]) #Keep updating/overwriting

        return res_arry
