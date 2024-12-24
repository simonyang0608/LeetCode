class Solution(object):
    def maxStrength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #============================================#
        # Recursion-based backtrack traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Result maximun product #####
        res_max_prod = [max(nums)]


        ##########################################
        #Recursion-based backtrack loop traversal
        if (len_nums == 1): #Issue/Boundary-case handling
            return res_max_prod[0]

        if (nums.count(0) == len_nums): #Issue/Boundary-case handling
            return res_max_prod[0]

        if ((nums.count(0) == (len_nums - 1)) and (sum(nums) < 0)): #Issue/Boundary-case handling
            return res_max_prod[0]

        self.recurseTraversal(nums, len_nums, 0, 1, res_max_prod) #Recursion function call

        return res_max_prod[0]

        
    def recurseTraversal(self, nums, len_nums, record_idx, record_prod, res_max_prod):
        """
        :type nums: List[int]
        :type len_nums: int
        :type record_idx: int
        :type record_prod: long long
        :type res_max_prod: List[long long]
        :rtype: None, void
        """
        #==============================================#
        # Recursion-based backtrack traversal function #
        #==============================================#
        if (record_idx >= len_nums): #Issue/Boundary-case handling
            res_max_prod[0] = max(res_max_prod[0], record_prod) #Update/Overwrite

            return

        if (not record_prod): #Issue/Boundary-case handling
            return

        self.recurseTraversal(nums, len_nums, (record_idx + 1), record_prod, res_max_prod) #Recursion function call (i.e. no get)
        self.recurseTraversal(nums, len_nums, (record_idx + 1), (record_prod * nums[record_idx]), res_max_prod) #Recursion function call (i.e. get)
