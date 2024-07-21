class Solution(object):
    def allCellsDistOrder(self, rows, cols, rCenter, cCenter):
        """
        :type rows: int
        :type cols: int
        :type rCenter: int
        :type cCenter: int
        :rtype: List[List[int]]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = []

        ##### Temporal dictionary/hashmap #####
        tmp_dict = {}

        for row_idx in range(rows):
            for col_idx in range(cols):
                if ((abs(rCenter-row_idx) + abs(cCenter-col_idx)) in tmp_dict):
                    tmp_dict[(abs(rCenter-row_idx) + abs(cCenter-col_idx))].append([row_idx, col_idx])
                else:
                    tmp_dict[(abs(rCenter-row_idx) + abs(cCenter-col_idx))] = [[row_idx, col_idx]]

        tmp_dict_len = len(tmp_dict)


        ###########################################################
        #Greedy-based loop traversal with coordinate distances map
        for tmp_idx in range(tmp_dict_len):
            res_arry += tmp_dict[tmp_idx] #Concate/Extend coordinate distances in sorted order

        return res_arry
