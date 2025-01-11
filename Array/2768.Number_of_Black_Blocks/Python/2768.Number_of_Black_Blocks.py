class Solution(object):
    def countBlackBlocks(self, m, n, coordinates):
        """
        :type m: int
        :type n: int
        :type coordinates: List[List[int]]
        :rtype: List[int]
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of coordinates array #####
        len_coordinates = len(coordinates)

        ##### Total summary counter #####
        total_cnter = ((m - 1) * (n - 1))

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record array #####
        record_arry = [[0, 0], [(-1), 0], [0, (-1)], [(-1), (-1)]]

        ##### Result array #####
        res_arry = [0 for _ in range(5)]


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record cells position informations with dictionary/hashmap #####
        for coordinates_idx in range(len_coordinates):
            for record_idx in range(4):
                rows_idx = ((coordinates[coordinates_idx])[0] + (record_arry[record_idx])[0]) #Rows index
                cols_idx = ((coordinates[coordinates_idx])[1] + (record_arry[record_idx])[1]) #Columns index

                ##### Check if the current indexed-position exceed boundary or not #####
                if (((rows_idx >= 0) and (rows_idx < (m - 1))) and ((cols_idx >= 0) and (cols_idx < (n - 1)))):

                    ##### Check if the current indexed-position existed or not #####
                    if ((rows_idx, cols_idx) not in record_dict):
                        record_dict[(rows_idx, cols_idx)] = 1 #Keep updating/recording
                    else: 
                        record_dict[(rows_idx, cols_idx)] += 1 #Keep updating/recording
                else:
                    pass

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_key in record_dict:
            res_arry[record_dict[record_key]] += 1 #Keep updating/accumulating

            total_cnter -= 1 #Keep updating/reducing

        res_arry[0] = total_cnter #Update/Overwrite

        return res_arry
