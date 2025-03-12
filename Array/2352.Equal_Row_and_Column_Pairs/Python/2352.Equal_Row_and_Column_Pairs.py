class Solution(object):
    def equalPairs(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counter #####
        res_cnter = 0


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record tuple lists with dictionary/hashmap #####
        for rows_idx in range(len_rows):
            record_tuple = tuple(grid[rows_idx]) #Record tuple

            ##### Check if the current tuple existed or not #####
            if (record_tuple not in record_dict):
                record_dict[record_tuple] = 1 #Keep updating/recording
            else:
                record_dict[record_tuple] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for cols_idx in range(len_cols):
            record_arry = [] #Record array

            for rows_idx in range(len_rows):
                record_arry.append((grid[rows_idx])[cols_idx]) #Keep updating/recording

            ##### Check if the current tuple existed or not #####
            if (tuple(record_arry) not in record_dict):
                continue

            res_cnter += record_dict[tuple(record_arry)] #Keep updating/accumulating

        return res_cnter
