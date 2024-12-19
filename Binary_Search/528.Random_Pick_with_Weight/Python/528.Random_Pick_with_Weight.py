class Solution(object):

    def __init__(self, w):
        """
        :type w: List[int]
        """
        #========================#
        # Constructor initialize #
        #========================#

        ############
        #Initialize
        ##### Record dynamic-programming (i.e. DP) array #####
        self.record_dp = w

        ##### Length of dynamic-programming array #####
        self.len_record_dp = len(w)


        ####################
        #Whole process/flow
        for self.record_idx in range(1, self.len_record_dp):
            (self.record_dp)[self.record_idx] += (self.record_dp)[(self.record_idx - 1)] #Keep updating/recording

        self.sum_record_dp = (self.record_dp)[(-1)] #Summary of dynamic-programming array #####
        

    def pickIndex(self):
        """
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right, middle) #####
        record_left_ptr, record_right_ptr = 0, (self.len_record_dp - 1)

        ##### Record target #####
        target = randint(0, (self.sum_record_dp - 1))


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if ((self.record_dp[record_mid_ptr] <= target)):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = record_mid_ptr #Keep updating/overwriting

        return record_left_ptr


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
