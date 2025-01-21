class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of heights array #####
        len_heights = (len(heights) + 1)

        ##### Record stack #####
        record_stack = []

        ##### Result maximun area #####
        res_max_area = 0


        ############################
        #Stack-based loop traversal
        heights.append(0) #Update/Record

        for heights_idx in range(len_heights):
            while (record_stack and (heights[heights_idx] <= heights[record_stack[(-1)]])):
                record_idx = record_stack.pop() #Keep updating/popped

                ##### Check if the curret stack is empty or not #####
                if (not record_stack):
                    res_max_area = max(res_max_area, (heights[record_idx] * heights_idx)) #Keep updating/overwriting
                else:
                    res_max_area = max(res_max_area, (heights[record_idx] * (heights_idx - record_stack[(-1)] - 1))) #Keep updating/overwriting

            record_stack.append(heights_idx) #Keep updating/recording

        return res_max_area
