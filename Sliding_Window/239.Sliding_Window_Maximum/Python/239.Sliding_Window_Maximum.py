class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        #==============================#
        # Deque-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record deque #####
        record_dq = []

        ##### Result array #####
        res_arry = []


        ############################
        #Deque-based loop traversal
        ##### Step 1: Looped-traversal for the first fixed-window #####
        for nums_idx in range(k):
            while (record_dq and ((record_dq[(-1)])[0] <= nums[nums_idx])):
                record_dq.pop() #Keep updating/popped

            record_dq.append((nums[nums_idx], nums_idx)) #Keep updating/recording

        ##### Step 2: Looped-traversal for the remainings #####
        res_arry.append((record_dq[0])[0]) #Update/Record
        
        for nums_idx in range(k, len_nums):
            while (record_dq and ((record_dq[0])[1] <= (nums_idx - k))):
                record_dq.pop(0) #Keep updating/popped

            while (record_dq and ((record_dq[(-1)])[0] <= nums[nums_idx])):
                record_dq.pop() #Keep updating/popped

            record_dq.append((nums[nums_idx], nums_idx)) #Keep updating/recording

            res_arry.append((record_dq[0])[0]) #Keep updating/recording

        return res_arry
