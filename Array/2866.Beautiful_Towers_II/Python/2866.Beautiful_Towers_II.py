class Solution(object):
    def maximumSumOfHeights(self, maxHeights):
        """
        :type maxHeights: List[int]
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of maxHeights array #####
        len_maxHeights = len(maxHeights)

        ##### Record pointers (i.e. left, right) #####
        record_arry_left, record_arry_right = [0 for _ in range(len_maxHeights)], [0 for _ in range(len_maxHeights)]

        ##### Record stacks (i.e. left, right) #####
        record_stack_left, record_stack_right = [], []

        ##### Result maximun summary value #####
        res_max_sum = 0


        #################################################
        #Stack-based loop traversal with recorded arrays
        ##### Step 1: Looped-traversal for the left-half part of array #####
        for heights_idx in range(len_maxHeights):
            while (record_stack_left and ((maxHeights[record_stack_left[(-1)]] > maxHeights[heights_idx]))):
                record_stack_left.pop() #Keep updating/popped
            
            ##### Check if the current stack is empty or not #####
            if (not record_stack_left):
                record_arry_left[heights_idx] = (maxHeights[heights_idx] * heights_idx) #Keep updating/overwriting
            else:
                record_arry_left[heights_idx] = (record_arry_left[record_stack_left[(-1)]] + maxHeights[record_stack_left[(-1)]] + 
                (maxHeights[heights_idx] * (heights_idx - record_stack_left[(-1)] - 1))) #Keep updating/overwriting
            
            record_stack_left.append(heights_idx) #Keep updating/recording

        ##### Step 2: Looped-traversal for the right-half part of array #####
        for heights_idx in range((len_maxHeights - 1), (-1), (-1)):
            while (record_stack_right and (maxHeights[record_stack_right[(-1)]] > maxHeights[heights_idx])):
                record_stack_right.pop() #Keep updating/popped

            ##### Check if the current stack is empty or not #####
            if (not record_stack_right):
                record_arry_right[heights_idx] = (maxHeights[heights_idx] * (len_maxHeights - heights_idx)) #Keep updating/overwriting
            else:
                record_arry_right[heights_idx] = (record_arry_right[record_stack_right[(-1)]] + (maxHeights[heights_idx] * 
                                                 (record_stack_right[(-1)] - heights_idx))) #Keep updating/overwriting

            record_stack_right.append(heights_idx) #Keep updating/recording

        ##### Step 3: Post-process, Final completions #####
        for heights_idx in range(len_maxHeights):
            res_max_sum = max(res_max_sum, (record_arry_left[heights_idx] + record_arry_right[heights_idx])) #Keep updating/overwriting

        return res_max_sum
