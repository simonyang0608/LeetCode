class Solution(object):
    def sortTheStudents(self, score, k):
        """
        :type score: List[List[int]]
        :type k: int
        :rtype: List[List[int]]
        """
        #===============================#
        # Sorted-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of rows #####
        len_rows = len(score)

        ##### Record array #####
        record_arry = []

        ##### Result array #####
        res_arry = []


        #################################################
        #Sorted-based loop traversal with recorded array
        ##### Step 1: Record indexed-value informations with array #####
        for rows_idx in range(len_rows):
            record_arry.append([(score[rows_idx])[k], rows_idx]) #Keep updating/recording

        ##### Step 2: Looped-traversal for the recorded array #####
        record_arry.sort(reverse = True) #Sorted-operations

        for rows_idx in range(len_rows):
            res_arry.append(score[(record_arry[rows_idx])[1]]) #Keep updating/recording

        return res_arry
