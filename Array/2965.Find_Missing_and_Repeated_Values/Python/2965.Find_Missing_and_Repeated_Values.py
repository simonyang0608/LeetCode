class Solution(object):
    def findMissingAndRepeatedValues(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length, Square of grid array #####
        len_grid = len(grid)
        sqre_grid = (len_grid ** 2)

        sqre_grid += 1

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result array #####
        res_arry = []

        
        #######################################################################
        #One-pass record based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for row_idx in range(len_grid):
            for col_idx in range(len_grid):

                ##### Check if the current indexed-value existed or not #####
                if ((grid[row_idx])[col_idx] not in record_dict):
                    record_dict[(grid[row_idx])[col_idx]] = True #Keep updating/recording
                else:
                    res_arry.append((grid[row_idx])[col_idx]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary #####
        for sqre_idx in range(1, sqre_grid):

            ##### Check if the current indexed-value existed or not #####
            if (sqre_idx not in record_dict):
                res_arry.append(sqre_idx) #Keep updating/recording

                break
            else:
                pass

        return res_arry
