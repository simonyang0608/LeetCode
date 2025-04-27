class Solution(object):
    def minimumTime(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #===================================#
        # Dijkstras' based traversal method #
        #===================================#
        if (((grid[0])[1] > 1) and ((grid[1])[0] > 1)): #Issue/Boundary-case handling
            return (-1)

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Edge rank array #####
        edge_rank_arry = [[float("inf") for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Directions array #####
        direct_arry = [[0, (-1)], [(-1), 0], [0, 1], [1, 0]]

        ##### Record heap/priority-queue #####
        record_pq = []


        ###################################################################
        #Dijkstras' based loop traversal with recorded heap/priority-queue
        heapify(record_pq) #Update/Heapify

        heappush(record_pq, (0, 0, 0)) #Update/Record

        (edge_rank_arry[0])[0] = 0 #Update/Record

        while (record_pq):
            (record_times, record_rows_idx, record_cols_idx) = record_pq[0] #Record times, rows and columns index

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current position information matched conditions or not #####
            if ((edge_rank_arry[record_rows_idx])[record_cols_idx] != record_times):
                continue

            ##### Check if the current position reached target or not #####
            if ((record_rows_idx == (len_rows - 1)) and (record_cols_idx == (len_cols - 1))):
                return record_times

            for direct_idx in range(4):
                next_rows_idx, next_cols_idx = (record_rows_idx + (direct_arry[direct_idx])[0]), (record_cols_idx + (direct_arry[direct_idx])[1]) #Next rows, columns index

                ##### Check if the next position exceed boundary or not #####
                if (((next_rows_idx < 0) or (next_rows_idx >= len_rows)) or ((next_cols_idx < 0) or (next_cols_idx >= len_cols))):
                    continue

                next_times = (record_times + 1) #Next times

                ##### Check if the next times matched conditions or not #####
                if (next_times >= (grid[next_rows_idx])[next_cols_idx]):

                    ##### Check if the next times matched conditions or not #####
                    if ((edge_rank_arry[next_rows_idx])[next_cols_idx] > next_times):
                        (edge_rank_arry[next_rows_idx])[next_cols_idx] = next_times #Keep updating/recording

                        heappush(record_pq, (next_times, next_rows_idx, next_cols_idx)) #Keep updating/recording
                    else:
                        pass
                else:
                    cycle_times = ((grid[next_rows_idx])[next_cols_idx] - next_times) #Cycle times

                    ##### Check if the current cycle times is odd or even #####
                    if (cycle_times & 1):
                        cycle_times += 1 #Keep updating/accumulating
                    else:
                        pass

                    next_times += cycle_times #Keep updating/accumulating

                    ##### Check if the next times matched conditions or not #####
                    if ((edge_rank_arry[next_rows_idx])[next_cols_idx] > next_times):
                        (edge_rank_arry[next_rows_idx])[next_cols_idx] = next_times #Keep updating/recording

                        heappush(record_pq, (next_times, next_rows_idx, next_cols_idx)) #Keep updating/recording
                    else:
                        pass

        return (-1)
