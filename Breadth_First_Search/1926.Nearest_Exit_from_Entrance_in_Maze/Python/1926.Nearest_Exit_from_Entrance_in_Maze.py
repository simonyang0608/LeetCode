class Solution(object):
    def nearestExit(self, maze, entrance):
        """
        :type maze: List[List[str]]
        :type entrance: List[int]
        :rtype: int
        """
        #==================================#
        # Queue-based BFS traversal method #
        #==================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(maze), len(maze[0])

        ##### Record queue #####
        record_queue = [(entrance[0], entrance[1])]

        ##### Record directions #####
        record_direc = [[0, (-1)], [(-1), 0], [0, 1], [1, 0]]

        ##### Result steps #####
        res_steps = 0


        ################################
        #Queue-based BFS loop traversal
        (maze[entrance[0]])[entrance[1]] = '+' #Update/Overwrite

        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                (rows_idx, cols_idx) = record_queue.pop(0) #Rows, Columns index

                for direc_idx in range(4):
                    next_rows_idx, next_cols_idx = (rows_idx + (record_direc[direc_idx])[0]), (cols_idx + (record_direc[direc_idx])[1]) #Next rows, columns index

                    ##### Check if the next position exceed boundary or not #####
                    if (((next_rows_idx < 0) or (next_rows_idx >= len_rows)) or ((next_cols_idx < 0) or (next_cols_idx >= len_cols))):
                        continue

                    ##### Check if the next position is wall or not #####
                    if ((maze[next_rows_idx])[next_cols_idx] == '+'):
                        continue

                    ##### Check if the next position is at boundary or not #####
                    if (((next_rows_idx <= 0) or (next_rows_idx >= (len_rows - 1))) or ((next_cols_idx <= 0) or (next_cols_idx >= (len_cols - 1)))):
                        return (res_steps + 1)

                    (maze[next_rows_idx])[next_cols_idx] = '+' #Keep updating/overwriting

                    record_queue.append((next_rows_idx, next_cols_idx)) #Keep updating/recording

            res_steps += 1 #Keep updating/accumulating

        return (-1)
