class Solution(object):
    def maxDistance(self, grid):
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

        ##### Record queue #####
        record_queue = []

        ##### Visit array #####
        visit_arry = [[0 for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Result step #####
        res_step = 0


        ###############################################################
        #Breath-first search based loop traversal withh recorded queue
        ##### Step 1: Record land cell with queue #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current cell is land or not #####
                if ((grid[rows_idx])[cols_idx]):
                    record_queue.append([rows_idx, cols_idx]) #Keep updating/recording
                else:
                    pass

        ##### Step 2: Looped-traversal with recorded queue #####
        if ((not record_queue) or (len(record_queue) == (len_rows * len_cols))): #Issue/Boundary-case handling
            return (-1)

        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                [rows_idx, cols_idx] = record_queue.pop(0) #Rows, Columns position

                ##### Check if the current position exceed boundary or not #####
                if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))):
                    continue

                ##### Check if the current cell is visited or not #####
                if ((visit_arry[rows_idx])[cols_idx]):
                    continue

                (visit_arry[rows_idx])[cols_idx] = 1 #Keep updating/overwriting

                record_queue.append([rows_idx, (cols_idx - 1)]) #Keep updating/recording
                record_queue.append([(rows_idx - 1), cols_idx]) #Keep updating/recording
                record_queue.append([rows_idx, (cols_idx + 1)]) #Keep updating/recording
                record_queue.append([(rows_idx + 1), cols_idx]) #Keep updating/recording

            res_step += 1 #Keep updating/accumulating

        return (res_step - 2)
