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

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Edge rank array #####
        edge_rank_arry = [[float("inf") for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Directions array #####
        direct_arry = [[0, (-1)], [(-1), 0], [0, 1], [1, 0]]


        ###################################################################
        #Dijkstras' based loop traversal with recorded heap/priority-queue
        heapify(record_pq) #Update/Heapify

        heappush(record_pq, (0, 0, 0)) #Update/Heappush

        (edge_rank_arry[0])[0] = 0 #Update/Overwrite

        while (record_pq):
            (record_times, record_rows_idx, record_cols_idx) = record_pq[0] #Record nodes informations

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current times matched conditions or not #####
            if (record_times != (edge_rank_arry[record_rows_idx])[record_cols_idx]):
                continue

            ##### Check if the current node position reached target or not #####
            if ((record_rows_idx == (len_rows - 1)) and (record_cols_idx == (len_cols - 1))):
                return record_times

            for direct_idx in range(4):
                next_rows_idx = (record_rows_idx + (direct_arry[direct_idx])[0]) #Next rows index
                next_cols_idx = (record_cols_idx + (direct_arry[direct_idx])[1]) #Next columns index

                ##### Check if the next node position exceed boundary or not #####
                if (((next_rows_idx < 0) or (next_rows_idx >= len_rows)) or ((next_cols_idx < 0) or (next_cols_idx >= len_cols))):
                    continue

                next_times = (max(record_times, (moveTime[next_rows_idx])[next_cols_idx]) + 1) #Next times

                ##### Check if the next times matched conditions or not #####
                if (next_times < (edge_rank_arry[next_rows_idx])[next_cols_idx]):
                    (edge_rank_arry[next_rows_idx])[next_cols_idx] = next_times #Keep updating/overwriting

                    heappush(record_pq, (next_times, next_rows_idx, next_cols_idx)) #Keep updating/recording
                else:
                    pass

        return (-1)
