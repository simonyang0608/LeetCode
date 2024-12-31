class Solution(object):
    def highestRankedKItems(self, grid, pricing, start, k):
        """
        :type grid: List[List[int]]
        :type pricing: List[int]
        :type start: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record array #####
        record_arry = [[0 for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Record queue, heap/priority-queue #####
        record_queue, record_pq = [start], []

        heapify(record_pq)

        ##### Record distance #####
        record_dist = 0

        ##### Result array #####
        res_arry = []


        ############################################################################
        #Breath-first search based loop traversal with recorded heap/priority-queue
        ##### Step 1: Record informations with heap/priority-queue #####
        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for _ in range(queue_size):
                [record_row_idx, record_col_idx] = record_queue.pop(0) #Keep updating/overwriting

                ##### Check if the current position exceed boundary or not #####
                if (((record_row_idx < 0) or (record_row_idx >= len_rows)) or ((record_col_idx < 0) or (record_col_idx >= len_cols))):
                    continue

                ##### Check if the current position is visited or not #####
                if ((record_arry[record_row_idx])[record_col_idx]):
                    continue

                (record_arry[record_row_idx])[record_col_idx] = 1 #Keep updating/overwriting

                record_val = (grid[record_row_idx])[record_col_idx] #Keep updating/overwriting

                ##### Check if the current position is valid or not #####
                if (not record_val):
                    continue

                ##### Check if the current price is in ranges or not #####
                if ((record_val >= pricing[0]) and (record_val <= pricing[1])):
                    heappush(record_pq, [record_dist, record_val, record_row_idx, record_col_idx]) #Keep updating/recording
                else:
                    pass

                record_queue.append([record_row_idx, (record_col_idx - 1)]) #Keep updating/recording
                record_queue.append([(record_row_idx - 1), record_col_idx]) #Keep updating/recording
                record_queue.append([record_row_idx, (record_col_idx + 1)]) #Keep updating/recording
                record_queue.append([(record_row_idx + 1), record_col_idx]) #Keep updating/recording

            record_dist += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal with recorded heap/priority-queue #####
        record_times = (k if (k < len(record_pq)) else len(record_pq)) #Record times 

        for record_idx in range(record_times):
            res_arry.append([(record_pq[0])[2], (record_pq[0])[3]]) #Keep updating/recording

            heappop(record_pq) #Keep updating/popped

        return res_arry
