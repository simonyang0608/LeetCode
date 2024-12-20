class Solution(object):
    def findBestValue(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, max(arr)

        ##### Record pointers (i.e. left, right-boundary) #####
        record_lb_ptr, record_rb_ptr = record_left_ptr, record_right_ptr

        ##### Record differences (i.e. left, right boundary) #####
        record_lb_diff, record_rb_diff = record_right_ptr, record_right_ptr

        ##### Result summary value #####
        res_sum = [0]


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            self.findSum(arr, len_arr, record_mid_ptr, res_sum) #Find-summary function call

            ##### Check if the current summary value mathed conditions or not #####
            if (res_sum[0] < target):
                record_lb_diff = (target - res_sum[0]) #Keep updating/overwriting

                record_lb_ptr = record_mid_ptr #Keep updating/overwriting

                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

            elif (res_sum[0] > target):
                record_rb_diff = (res_sum[0] - target) #Keep updating/overwriting

                record_rb_ptr = record_mid_ptr #Keep updating/overwriting

                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                return record_mid_ptr

            ##### Check if the current summary value needs to be reset or not #####
            if (res_sum[0]):
                res_sum[0] &= 0 #Keep updating/reset
            else:
                pass

        return (record_lb_ptr if (record_lb_diff <= record_rb_diff) else record_rb_ptr)

        
    def findSum(self, arr, len_arr, record_val, res_sum):
        """
        :type arr: List[int]
        :type len_arr: int
        :type record_val: int
        :type res_sum: List[int]
        :rtype: None, void
        """

        ####################
        #Whole process/flow
        for record_idx in range(len_arr):
            res_sum[0] += min(arr[record_idx], record_val) #Keep updating/accumulating
