class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of edge #####
        len_edge = len(matrix)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_edge - 1)


        ###################################
        #Two-pointers based loop traversal
        while (record_left_ptr <= record_right_ptr):
            self.rotateEdge(matrix, record_left_ptr, record_right_ptr) #Rotation function call

            record_left_ptr += 1 #Keep updating/traversing
            record_right_ptr -= 1 #Keep updating/traversing


    def rotateEdge(self, matrix, record_left_ptr, record_right_ptr):
        """
        :type matrix: List[List[int]]
        :type record_left_ptr: int
        :type record_right_ptr: int
        :rtype: None, void
        """

        ############
        #Initialize
        ##### Record array #####
        record_arry = (matrix[record_left_ptr])[:]

        ###################
        #Whoe process/flow
        for left_idx in range((record_right_ptr - record_left_ptr)):
            (matrix[record_left_ptr])[(record_left_ptr + left_idx)] = (matrix[(record_right_ptr - left_idx)])[record_left_ptr] #Keep updating/overwriting

        for down_idx in range(record_right_ptr, record_left_ptr, (-1)):
            (matrix[down_idx])[record_left_ptr] = (matrix[record_right_ptr])[down_idx] #Keep updating/overwriting

        for right_idx in range((record_right_ptr - record_left_ptr)):
            (matrix[record_right_ptr])[(record_right_ptr - right_idx)] = (matrix[(record_left_ptr + right_idx)])[record_right_ptr] #Keep updating/overwriting

        for up_idx in range(record_left_ptr, record_right_ptr):
            (matrix[up_idx])[record_right_ptr] = record_arry[up_idx] #Keep updating/overwriting
