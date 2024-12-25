class Solution(object):
    def minimumOperationsToWriteY(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #===========================================#
        # Dictionary/Hashmap based traversal method #
        #===========================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record y-internal summary counter #####
        record_y_cnter = (((len_rows // 2) + 1) + ((len_rows // 2) * 2))

        ##### Record y-external summary counter #####
        record_ext_cnter = ((len_rows * len_cols) - record_y_cnter)

        ##### Record dictionary/hashmap (i.e. y-internal, external) #####
        record_y_dict, record_ext_dict = {0: 0, 1: 0, 2: 0}, {0: 0, 1: 0, 2: 0}


        #########################################
        #Dictionary/Hashmap based loop traversal
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for record_idx in range((len_rows // 2)):
            record_y_dict[(grid[record_idx])[record_idx]] += 1 #Keep updating/recording
            record_y_dict[(grid[record_idx])[((len_cols - 1) - record_idx)]] += 1 #Keep updating/recording

            (grid[record_idx])[record_idx] = 3 #Keep updating/overwriting
            (grid[record_idx])[((len_cols - 1) - record_idx)] = 3 #Keep updating/overwriting

        record_y_dict[(grid[(len_rows // 2)])[(len_rows // 2)]] += 1 #Update/Record

        (grid[(len_rows // 2)])[(len_rows // 2)] = 3 #Update/Overwrite

        for record_idx in range(((len_rows // 2) + 1), len_rows):
            record_y_dict[(grid[record_idx])[(len_rows // 2)]] += 1 #Keep updating/recording

            (grid[record_idx])[(len_rows // 2)] = 3 #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx] == 3):
                    continue

                record_ext_dict[(grid[rows_idx])[cols_idx]] += 1 #Keep updating/recording

        return min(((record_y_cnter - record_y_dict[0]) + (record_ext_cnter - max(record_ext_dict[1], record_ext_dict[2]))), ((record_y_cnter - record_y_dict[1]) + (record_ext_cnter - max(record_ext_dict[0], record_ext_dict[2]))), ((record_y_cnter - record_y_dict[2]) + (record_ext_cnter - max(record_ext_dict[0], record_ext_dict[1]))))
