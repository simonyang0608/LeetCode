class Solution(object):
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Breath-first-search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of board array #####
        len_board = len(board)

        ##### Total steps #####
        total_step = (len_board * len_board)

        ##### Record queue #####
        record_queue = [1]

        ##### Record array #####
        record_arry = [0 for _ in range((total_step + 1))]

        ##### Result minimun step #####
        res_min_step = 0


        ##############################################################
        #Breath-first-search based loop traversal with recorded array
        record_arry[1] = 1 #Update/Overwrite

        while (record_queue):
            for queue_idx in range(len(record_queue), 0, (-1)):
                record_step = record_queue.pop(0) #Record step

                ##### Check if the current step reached destinations or not #####
                if (record_step == total_step):
                    return res_min_step

                for record_idx in range(1, min(7, ((total_step - record_step) + 1))):
                    [res_row_idx, res_col_idx] = self.getPosition((record_step + record_idx), len_board) #Get positions 

                    ##### Check if the next-step is valid or not #####
                    if ((board[res_row_idx])[res_col_idx] == (-1)):
                        next_step = (record_step + record_idx) #Keep updating/overwriting
                    else:
                        next_step = (board[res_row_idx])[res_col_idx] #Keep updating/overwriting

                    ##### Check if the next-step is visited or not #####
                    if (record_arry[next_step]):
                        continue

                    record_arry[next_step] = 1 #Keep updating/overwriting

                    record_queue.append(next_step) #Keep updating/recording

            res_min_step += 1 #Keep updating/accumulating

        return (-1)

    
    def getPosition(self, next_step, len_board):
        """
        :type next_step: int
        :type len_board: int
        :rtype: List[int]
        """
        
        ############
        #Initialize
        ##### Record quotient, remainings
        record_quot, record_remain = (next_step // len_board), (next_step % len_board)

        ##### Result indexes (i.e. row, column) #####
        res_row_idx = ((len_board - (record_quot + 1)) if (record_remain) else (len_board - record_quot))


        ####################
        #Whole process/flow
        ##### Check if the current remainings matched conditions or not #####
        if (not record_remain):
            res_col_idx = ((len_board - 1) if ((record_quot % 2)) else 0) #Update/Overwrite
        else:
            res_col_idx = ((record_remain - 1) if ((len_board - res_row_idx) % 2) else (len_board - record_remain)) #Update/Overwrite

        return [res_row_idx, res_col_idx]
