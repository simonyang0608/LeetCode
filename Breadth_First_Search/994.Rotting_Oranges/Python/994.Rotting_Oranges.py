class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Directions array #####
        direc_arry = [[0, (-1)], [(-1), 0], [0, 1], [1, 0]]

        ##### Record queue #####
        record_queue = []

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result minimun times #####
        res_min_times = 0


        ##########################################
        #Breath-first search based loop traversal
        ##### Step 1: Record indexed-value with queue #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx] == 1):
                    record_cnter += 1 #Keep updating/accumulating

                elif ((grid[rows_idx])[cols_idx] == 2):
                    record_queue.append([rows_idx, cols_idx]) #Keep updating/recording
                else:
                    pass

        ##### Step 2: Looped-traversal with recorded queue #####
        if ((not record_queue) and record_cnter): #Issue/Boundary-case handling
            return (-1)

        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                [rows_idx, cols_idx] = record_queue.pop(0) #Rows, Columns index

                for direc_idx in range(4):
                    next_rows_idx, next_cols_idx = (rows_idx + (direc_arry[direc_idx])[0]), (cols_idx + (direc_arry[direc_idx])[1]) #Next rows, columns index

                    ##### Check if the next positions matched conditions or not #####
                    if (((next_rows_idx < 0) or (next_rows_idx >= len_rows)) or ((next_cols_idx < 0) or (next_cols_idx >= len_cols))):
                        continue

                    if ((grid[next_rows_idx])[next_cols_idx] != 1):
                        continue

                    record_queue.append([next_rows_idx, next_cols_idx]) #Keep updating/recording

                    (grid[next_rows_idx])[next_cols_idx] = 2 #Keep updating/overwriting

                    record_cnter -= 1 #Keep updating/reducing

            res_min_times += 1 #Keep updating/accumulating

        if (not res_min_times): #Issue/Boundary-case handling
            return 0

        return ((res_min_times - 1) if (not record_cnter) else (-1))
