class Solution(object):
    def rotateTheBox(self, boxGrid):
        """
        :type boxGrid: List[List[str]]
        :rtype: List[List[str]]
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(boxGrid), len(boxGrid[0])

        ##### Result array #####
        res_arry = [['.' for _ in range(len_rows)] for _ in range(len_cols)]


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-traversal for modifying the original matrix/grid #####
        for rows_idx in range(len_rows):

            record_cols_idx = (-1) #Record columns index

            for cols_idx in range((len_cols - 1), (-1), (-1)):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((boxGrid[rows_idx])[cols_idx] == '.'):

                    ##### Check if the current index matched conditions or not #####
                    if (record_cols_idx == (-1)):
                        record_cols_idx = cols_idx #Keep updating/overwriting
                    else:
                        pass

                elif ((boxGrid[rows_idx])[cols_idx] == '*'):

                    ##### Check if the current index matched conditions or not #####
                    if (record_cols_idx != (-1)):
                        record_cols_idx = (-1) #Keep updating/overwriting
                    else:
                        pass

                else:
                    ##### Check if the current index matched conditions or not #####
                    if (record_cols_idx != (-1)):
                        (boxGrid[rows_idx])[cols_idx], (boxGrid[rows_idx])[record_cols_idx] = (boxGrid[rows_idx])[record_cols_idx], (boxGrid[rows_idx])[cols_idx] #Swap operations

                        record_cols_idx -= 1 #Keep updating/traversing
                    else:
                        pass

        ##### Step 2: Post-process/Final completions #####
        for cols_idx in range(len_cols):
            for rows_idx in range(len_rows):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((boxGrid[len_rows - 1 - rows_idx])[cols_idx] == '.'):
                    continue
                
                (res_arry[cols_idx])[rows_idx] = (boxGrid[len_rows - 1 - rows_idx])[cols_idx] #Keep updating/overwriting

        return res_arry
