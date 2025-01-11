class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of height array #####
        len_height = len(height)

        if (len_height < 3): #Issue/Boundary-case handling
            return 0

        ##### Record dynamic-programming arrays (i.e. left, right) #####
        record_dp_left, record_dp_right = [0 for _ in range(len_height)], [0 for _ in range(len_height)]

        ##### Result summary value #####
        res_sum_val = 0


        ##########################################
        #Dynamic-programming based loop traversal
        ##### Step 1: Record left, right-boundary values with dynamic-programmign array #####
        record_dp_left[0], record_dp_left[1] = (-1), height[0] #Update/Overwrite
        record_dp_right[(len_height - 1)], record_dp_right[(len_height - 2)] = (-1), height[(len_height - 1)] #Update/Overwrite

        for height_idx in range(2, len_height):
            record_dp_left[height_idx] = max(record_dp_left[(height_idx - 1)], height[(height_idx - 1)]) #Keep updating/overwriting
        
        for height_idx in range((len_height - 3), (-1), (-1)):
            record_dp_right[height_idx] = max(record_dp_right[(height_idx + 1)], height[(height_idx + 1)]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dynamic-programming array #####
        for height_idx in range(1, (len_height - 1)):
            record_mmax = (record_dp_left[height_idx] if (record_dp_left[height_idx] < record_dp_right[height_idx]) else record_dp_right[height_idx]) #Record minimun max-value

            ##### Check if the current height can trap water or not #####
            if (record_mmax > height[height_idx]):
                res_sum_val += (record_mmax - height[height_idx]) #Keep updating/accumulating
            else:
                pass

        return res_sum_val
