class Solution(object):
    def maximumWhiteTiles(self, tiles, carpetLen):
        """
        :type tiles: List[List[int]]
        :type carpetLen: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of tiles array #####
        len_tiles = len(tiles)

        ##### Prefix-summary array #####
        prefix_sum = [0 for _ in range((len_tiles + 1))]

        ##### Result maximun window-size #####
        res_max_window = 0


        #######################################################################
        #Binary-search based loop traversal with recorded prefix-summary array
        ##### Step 1: Record indexed-intervals with prefix-summary array #####
        tiles.sort() #Sorted-operations

        for tiles_idx in range(1, (len_tiles + 1)):
            prefix_sum[tiles_idx] += ((prefix_sum[(tiles_idx - 1)] + ((tiles[(tiles_idx - 1)])[1] - (tiles[(tiles_idx - 1)])[0] + 1))) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded prefix-summary array #####
        for tiles_idx in range(len_tiles):
            prev_edge = ((tiles[tiles_idx])[1] - carpetLen + 1) #Previous edge

            ##### Check if the current previous edge is less than 1 or not #####
            if (prev_edge < 1):
                prev_edge = 1 #Keep updating/overwriting
            else:
                pass

            record_idx = self.binarySearch(len_tiles, tiles, prev_edge) #Record index

            record_window = (prefix_sum[(tiles_idx + 1)] - prefix_sum[(record_idx + 1)]) #Record window

            ##### Check if the previous edge matched conditions or not #####
            if (prev_edge > (tiles[record_idx])[0]):
                record_window += ((tiles[record_idx])[1] - prev_edge + 1) #Keep updating/accumulating
            else:
                record_window += ((tiles[record_idx])[1] - (tiles[record_idx])[0] + 1) #Keep updating/accumulating

            res_max_window = max(res_max_window, record_window) #Keep updating/overwriting

        return res_max_window
        

    def binarySearch(self, len_tiles, tiles, prev_edge):
        """
        :type len_tiles: int
        :type tiles: List[List[int]]
        :type prev_edge: int
        :rtype: int
        """
        #========================================#
        # Binary-search based traversal function #
        #========================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_tiles - 1)

        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current value matched conditions or not #####
            if ((tiles[record_mid_ptr])[1] < prev_edge):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return record_left_ptr
