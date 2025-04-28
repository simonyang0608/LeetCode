class Solution(object):
    def minTimeToReach(self, moveTime):
        """
        :type moveTime: List[List[int]]
        :rtype: int
        """
        #===================================#
        # Dijkstras' based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(moveTime), len(moveTime[0])

        ##### Edge rank array #####
        edge_rank_arry = [[float("inf") for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Directions array #####
        direct_arry = [[0, (-1)], [(-1), 0], [0, 1], [1, 0]]

        ##### Record heap/priority-queue #####
        record_pq = []


        ###################################################################
        #Dijkstras' based loop traversal with recorded heap/priority-queue
        heapify(record_pq) #Update/Heapify

        heappush(record_pq, (0, 0, 0, 1)) #Update/Record

        (edge_rank_arry[0])[0] = 0 #Update/Record

        while (record_pq):
            (record_times, record_rows_idx, record_cols_idx, record_moves) = record_pq[0] #Record informations

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current times matched conditions or not #####
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

                next_times = (record_times if (record_times > (moveTime[next_rows_idx])[next_cols_idx]) else (moveTime[next_rows_idx])[next_cols_idx]) #Next times

                next_times += record_moves #Keep updating/accumulating

                ##### Check if the next times information matched conditions or not #####
                if ((edge_rank_arry[next_rows_idx])[next_cols_idx] > next_times):
                    (edge_rank_arry[next_rows_idx])[next_cols_idx] = next_times #Keep updating/recording

                    heappush(record_pq, (next_times, next_rows_idx, next_cols_idx, (2 if (record_moves == 1) else 1))) #Keep updating/recording
                else:
                    pass

        return (-1)
