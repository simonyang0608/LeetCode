class Solution(object):
    def swimInWater(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record values (i.e. minimun, maximun) #####
        record_min_val, record_max_val = 2500, (-1)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0


        ####################################
        #Binary-search based loop traversal
        ##### Step 1: Looped-traversal for searching for the min, max values #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):
                record_min_val = ((grid[rows_idx])[cols_idx] if ((grid[rows_idx])[cols_idx] < record_min_val) else record_min_val) #Keep updating/overwriting
                record_max_val = ((grid[rows_idx])[cols_idx] if ((grid[rows_idx])[cols_idx] > record_max_val) else record_max_val) #Keep updating/overwriting

        ##### Step 2: Post-process/Final completions #####
        record_right_ptr = (record_max_val - record_min_val) #Update/Overwrite

        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            record_flag = self.isValid(len_rows, len_cols, grid, record_mid_ptr) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (not record_flag):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = record_mid_ptr #Keep updating/overwriting

        return record_left_ptr


    def isValid(self, len_rows, len_cols, grid, record_val):
        """
        :type len_rows: int
        :type len_cols: int
        :type grid: List[List[int]]
        :type record_val: int
        :rtype: bool
        """
        if ((grid[0])[0] > record_val): #Issue/Boundary-case handling
            return False

        ############
        #Initialize
        ##### Visit array #####
        visit_arry = [[False for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Record queue #####
        record_queue = [[0, 0]]

        ##### Directions array #####
        direc_arry = [[0, (-1)], [(-1), 0], [0, 1], [1, 0]]


        ####################
        #Whole process/flow
        (visit_arry[0])[0] = True #Update/Record

        while (record_queue):
            len_queue = len(record_queue) #Length of queue 

            for queue_idx in range(len_queue):
                record_rows_idx, record_cols_idx = (record_queue[0])[0], (record_queue[0])[1] #Record rows, columns index

                record_queue.pop(0) #Keep updating/popped

                ##### Check if the current position reached target or not #####
                if ((record_rows_idx == (len_rows - 1)) and (record_cols_idx == (len_cols - 1))):
                    return True

                for direc_idx in range(4):
                    next_rows_idx, next_cols_idx = (record_rows_idx + (direc_arry[direc_idx])[0]), (record_cols_idx + (direc_arry[direc_idx])[1]) #Next rows, columns index

                    ##### Check if the next position exceed boundary or not #####
                    if (((next_rows_idx < 0) or (next_rows_idx >= len_rows)) or ((next_cols_idx < 0) or (next_cols_idx >= len_cols))):
                        continue

                    ##### Check if the next position is visited or not #####
                    if ((visit_arry[next_rows_idx])[next_cols_idx]):
                        continue

                    ##### Check if the current difference matched conditions or not #####
                    if ((grid[next_rows_idx])[next_cols_idx] > record_val):
                        continue

                    (visit_arry[next_rows_idx])[next_cols_idx] = True #Keep updating/recording

                    record_queue.append([next_rows_idx, next_cols_idx]) #Keep updating/recording
        
        return False
