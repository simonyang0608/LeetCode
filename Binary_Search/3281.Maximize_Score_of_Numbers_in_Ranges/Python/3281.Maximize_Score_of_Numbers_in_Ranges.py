class Solution(object):
    def maxPossibleScore(self, start, d):
        """
        :type start: List[int]
        :type d: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of start array #####
        len_start = len(start)

        ####################################
        #Binary-search based loop traversal
        start.sort() #Sorted operations

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, ((start[(-1)] - start[0]) + d)

        if (len_start == 2): #Issue/Boundary-case handling
            return record_right_ptr

        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) // 2) #Record middle pointer

            record_flag = self.chackMax(len_start, start, record_mid_ptr, d) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (not record_flag):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = record_mid_ptr #Keep updating/overwriting

        return record_left_ptr

    
    def chackMax(self, len_start, start, record_val, diff):
        """
        :type len_start: int
        :type start: List[int]
        :type record_val: int
        :type diff: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Prefix-value #####
        prefix_val = start[0]

        ####################
        #Whole process/flow
        for start_idx in range(1, len_start):

            ##### Check if the current value matched conditions or not #####
            if (((start[start_idx] - prefix_val) + diff) < record_val):
                return False

            prefix_val = max((prefix_val + record_val), start[start_idx]) #Keep updating/overwriting

        return True
