class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #==================================#
        # Heap-sort based traversal method #
        #==================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ################################
        #Heap-sort based loop traversal
        ##### Step 1: Looped-traversal for bottom-up tree-nodes ##### 
        for record_idx in range(((len_nums - 1) // 2), (-1), (-1)):
            self.heapSort(nums, len_nums, record_idx) #Recursion function call (i.e. button-up)

        ##### Step 2: Post-process, Final completions #####
        for record_idx in range((len_nums - 1), 0, (-1)):
            nums[0], nums[record_idx] = nums[record_idx], nums[0] #Keep updating, swapped

            self.heapSort(nums, record_idx, 0) #Recursion function call

        return nums


    def heapSort(self, nums, len_nums, record_idx):
        """
        :type nums: List[int]
        :type len_nums: int
        :type record_idx: int
        :rtype: None, void
        """
        #====================================#
        # Recursion-based traversal function #
        #====================================#
        
        ############
        #Initialize
        ##### Record indexes (i.e. left, right) #####
        record_left_idx, record_right_idx = ((record_idx * 2) + 1), ((record_idx * 2) + 2)

        ##### Result index #####
        res_idx = record_idx


        ####################
        #Whole process/flow
        ##### Check if the current indexed-value is larger or not #####
        if ((record_left_idx < len_nums) and (nums[record_left_idx] >= nums[res_idx])):
            res_idx = record_left_idx #Keep updating/overwriting
        else:
            pass

        if ((record_right_idx < len_nums) and (nums[record_right_idx] >= nums[res_idx])):
            res_idx = record_right_idx #Keep updating/overwriting
        else:
            pass

        ##### Check if the current indexed-value matched conditions or not #####
        if (res_idx != record_idx):
            nums[record_idx], nums[res_idx] = nums[res_idx], nums[record_idx] #Update/Swapped

            self.heapSort(nums, len_nums, res_idx) #Recursion function call

        return
