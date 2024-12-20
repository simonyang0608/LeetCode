class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of height array #####
        len_height = len(height)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_height - 1)

        ##### Result maximun summary value #####
        res_max_sum = (-1)


        ###################################
        #Two-pointers based loop traversal
        while (record_left_ptr < record_right_ptr):
            res_max_sum = max(res_max_sum, (min(height[record_left_ptr], height[record_right_ptr]) * (record_right_ptr - record_left_ptr))) #Keep updating/overwriting

            ##### Check if the current indexed-value is smaller or not #####
            if (height[record_left_ptr] < height[record_right_ptr]):
                record_left_ptr += 1 #Keep updating/traversing
            else:
                record_right_ptr -= 1 #Keep updating/traversing

        return res_max_sum
