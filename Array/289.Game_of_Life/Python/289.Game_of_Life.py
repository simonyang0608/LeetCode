class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(board), len(board[0])

        ##### Record queue #####
        record_queue = [[0, 0]]

        ##### Record board #####
        record_board = [[(-1) for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Record dictionary/hashmap #####
        record_dict = {}


        ##########################################
        #Breath-first search based loop traversal
        ##### Step 1: Record transform positions with queue, dictionary/hashmap, ... #####
        while (record_queue):
            queue_size = len(record_queue) #Queue size

            for queue_idx in range(queue_size):
                record_row_idx, record_col_idx = (record_queue[0])[0], (record_queue[0])[1] #Record indexes (i.e. row, column)

                record_queue.pop(0) #Keep updating/popped

                ##### Check if the current position is valid or not #####
                if (((record_row_idx < 0) or (record_row_idx >= len_rows)) or ((record_col_idx < 0) or (record_col_idx >= len_cols))):
                    continue

                if ((record_board[record_row_idx])[record_col_idx] != (-1)):
                    continue

                (record_board[record_row_idx])[record_col_idx] = 2 #Keep updating/overwriting

                self.boardTransform(board, len_rows, len_cols, record_row_idx, record_col_idx, record_dict) #Transform function call

                ##### Record for the next positions #####
                record_queue.append([(record_row_idx - 1), record_col_idx])
                record_queue.append([(record_row_idx + 1), record_col_idx])
                record_queue.append([record_row_idx, (record_col_idx - 1)])
                record_queue.append([record_row_idx, (record_col_idx + 1)])

                record_queue.append([(record_row_idx - 1), (record_col_idx - 1)])
                record_queue.append([(record_row_idx + 1), (record_col_idx + 1)])
                record_queue.append([(record_row_idx - 1), (record_col_idx + 1)])
                record_queue.append([(record_row_idx + 1), (record_col_idx - 1)])

        ##### Step 2 : Post-process/Final completions #####
        for (record_row_idx, record_col_idx) in record_dict:

            ##### Check if the current cell is live or dead #####
            if ((board[record_row_idx])[record_col_idx]):
                (board[record_row_idx])[record_col_idx] = 0 #Keep updating/overwriting
            else:
                (board[record_row_idx])[record_col_idx] = 1 #Keep updating/overwriting


    def boardTransform(self, board, len_rows, len_cols, record_row_idx, record_col_idx, record_dict):
        """
        :type board: List[List[int]]
        :type len_rows: int
        :type len_cols: int
        :type record_row_idx: int
        :type record_col_idx: int
        :type record_dict: dict
        :rtype: None, void
        """

        ############
        #Initialize
        ##### Result lives summary counter #####
        res_lives_cnter = 0

        ####################
        #Whole process/flow
        ##### Update/Accumulate for the matched conditions neighbors #####
        res_lives_cnter += (1 if (((record_row_idx - 1) >= 0) and ((board[(record_row_idx - 1)])[record_col_idx])) else 0)
        res_lives_cnter += (1 if (((record_col_idx - 1) >= 0) and ((board[record_row_idx])[(record_col_idx - 1)])) else 0)
        res_lives_cnter += (1 if (((record_row_idx + 1) < len_rows) and ((board[(record_row_idx + 1)])[record_col_idx])) else 0)
        res_lives_cnter += (1 if (((record_col_idx + 1) < len_cols) and ((board[record_row_idx])[(record_col_idx + 1)])) else 0)

        res_lives_cnter += (1 if ((((record_row_idx - 1) >= 0) and ((record_col_idx - 1) >= 0)) and ((board[(record_row_idx - 1)])[(record_col_idx - 1)])) else 0)
        res_lives_cnter += (1 if ((((record_row_idx + 1) < len_rows) and ((record_col_idx + 1) < len_cols)) and ((board[(record_row_idx + 1)])[(record_col_idx + 1)])) else 0)
        res_lives_cnter += (1 if ((((record_row_idx - 1) >= 0) and ((record_col_idx + 1) < len_cols)) and ((board[(record_row_idx - 1)])[(record_col_idx + 1)])) else 0)
        res_lives_cnter += (1 if ((((record_row_idx + 1) < len_rows) and ((record_col_idx - 1) >= 0)) and ((board[(record_row_idx + 1)])[(record_col_idx - 1)])) else 0)

        ##### Check if the current cell is live or dead #####
        if ((board[record_row_idx])[record_col_idx]):

            ##### Check if the current lives summary counter matched conditions or not #####
            if (res_lives_cnter < 2):
                record_dict[(record_row_idx, record_col_idx)] = True #Update/Record
            
            elif (res_lives_cnter > 3):
                record_dict[(record_row_idx, record_col_idx)] = True #Update/Record
            else:
                pass

        else:
            ##### Check if the current lives summary counter matched conditions or not #####
            if (res_lives_cnter == 3):
                record_dict[(record_row_idx, record_col_idx)] = True #Update/Record
            else:
                pass
