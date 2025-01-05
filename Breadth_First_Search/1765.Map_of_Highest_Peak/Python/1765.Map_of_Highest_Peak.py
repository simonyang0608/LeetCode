class Solution(object):
    def highestPeak(self, isWater):
        """
        :type isWater: List[List[int]]
        :rtype: List[List[int]]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(isWater), len(isWater[0])

        ##### Record queue #####
        record_queue = []

        ##### Visit array #####
        visit_arry = [[0 for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Result array #####
        res_arry = [[0 for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Result steps #####
        res_step = 0


        ##############################################################
        #Breath-first search based loop traversal with recorded queue
        ##### Step 1: Record cell positions with queue #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current cell position is water or not #####
                if ((isWater[rows_idx])[cols_idx]):
                    record_queue.append([rows_idx, cols_idx]) #Keep updating/recording
                else:
                    pass

        ##### Step 2: Looped-traversal with recorded queue #####
        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                [record_rows_idx, record_cols_idx] = record_queue.pop(0) #Record rows, columns informations

                ##### Check if the current position exceed boundary or not #####
                if (((record_rows_idx < 0) or (record_rows_idx >= len_rows)) or ((record_cols_idx < 0) or (record_cols_idx >= len_cols))):
                    continue

                ##### Check if the current cell is visited or not #####
                if ((visit_arry[record_rows_idx])[record_cols_idx]):
                    continue

                (visit_arry[record_rows_idx])[record_cols_idx] = 1 #Keep updating/overwriting

                (res_arry[record_rows_idx])[record_cols_idx] = res_step #Keep updating/overwriting

                record_queue.append([record_rows_idx, (record_cols_idx - 1)]) #Keep updating/recording (i.e. left)
                record_queue.append([(record_rows_idx - 1), record_cols_idx]) #Keep updating/recording (i.e. up)
                record_queue.append([record_rows_idx, (record_cols_idx + 1)]) #Keep updating/recording (i.e. right)
                record_queue.append([(record_rows_idx + 1), record_cols_idx]) #Keep updating/recording (i.e. down)

            res_step += 1 #Keep updating/accumulating

        return res_arry
