class Solution(object):
    def platesBetweenCandles(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of s string, queries array #####
        len_s, len_queries = len(s), len(queries)

        ##### Plates, Prefix-summary arrays #####
        plates_arry, prefixSum_arry = [], [0 for _ in range(len_s)]

        ##### Record flag #####
        record_flag = False

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result array #####
        res_arry = [0 for _ in range(len_queries)]


        ########################################################################
        #Binary-search based loop traversal with recorded prefix-summary array
        ##### Step 1: Record summary counter with prefix-summary array #####
        for s_idx in range(len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[s_idx] == '*'):

                ##### Check if the current flag matched conditions or not #####
                if (record_flag):
                    record_cnter += 1 #Keep updating/accumulating
                else:
                    pass
            else:
                plates_arry.append(s_idx) #Keep updating/recording

                ##### Check if the current flag matched conditions or not #####
                if (record_flag):
                    prefixSum_arry[s_idx] = record_cnter #Keep updating/overwriting
                else:
                    record_flag |= True #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded prefix-summary array #####
        if (not plates_arry): #Issue/Boundary-case handling
            return res_arry

        for queries_idx in range(len_queries):
            left_idx = self.binarySearch_left(plates_arry, (queries[queries_idx])[0]) #Left index
            right_idx = self.binarySearch_right(plates_arry, (queries[queries_idx])[1]) #Right index

            ##### Check if the index boundary is valid or not #####
            if (left_idx < right_idx):
                res_arry[queries_idx] = (prefixSum_arry[right_idx] - prefixSum_arry[left_idx]) #Keep updating/overwriting
            else:
                pass

        return res_arry


    def binarySearch_left(self, plates_arry, left_val):
        """
        :type plates_arry: List[int]
        :type left_val: int
        :rtype: int
        """
        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(plates_arry) - 1)

        #####################
        #Whole process/flow
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer 

            ##### Check if the current indexed-value is larger than target or not #####
            if (plates_arry[record_mid_ptr] >= left_val):
                record_right_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        return plates_arry[record_left_ptr]


    def binarySearch_right(self, plates_arry, right_val):
        """
        :type plates_arry: List[int]
        :type right_val: int
        :rtype: int
        """
        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(plates_arry) - 1)

        #####################
        #Whole process/flow
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) // 2) #Record middle pointer

            ##### Check if the current indexed-value is larger than target or not #####
            if (plates_arry[record_mid_ptr] > right_val):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = record_mid_ptr #Keep updating/overwriting

        return plates_arry[record_left_ptr]
