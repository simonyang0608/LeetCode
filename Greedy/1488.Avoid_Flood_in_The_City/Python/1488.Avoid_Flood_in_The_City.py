class Solution(object):
    def avoidFlood(self, rains):
        """
        :type rains: List[int]
        :rtype: List[int]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of rains array #####
        len_rains = len(rains)

        ##### Record sorted-array #####
        record_arry = SortedList([])

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result array #####
        res_arry = [(-1) for _ in range(len_rains)]


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        for rains_idx in range(len_rains):

            ##### Check if the current indexed-value matched conditions or not #####
            if (not rains[rains_idx]):
                record_arry.add(rains_idx) #Keep updating/recording
            else:
                ##### Check if the current indexed-value existed or not #####
                if (rains[rains_idx] not in record_dict):
                    record_dict[rains[rains_idx]] = rains_idx #Keep updating/recording
                else:
                    record_idx = self.binarySearch(record_arry, record_dict[rains[rains_idx]]) #Record index

                    ##### Check if the current index matched conditions or not #####
                    if (record_idx == (-1)):
                        return []

                    res_arry[record_idx] = rains[record_dict[rains[rains_idx]]] #Keep updating/overwriting

                    record_arry.remove(record_idx) #Keep updating/deleting

                    record_dict[rains[rains_idx]] = rains_idx #Keep updating/recording
        
        for record_idx in record_arry:
            res_arry[record_idx] = 1 #Keep updating/overwriting

        return res_arry


    def binarySearch(self, record_arry, record_val):
        """
        :type record_arry: List[int]
        :type record_val: int
        :rtype: int
        """

        ############
        #Initialize
        ##### Lenght of record sorted-array #####
        len_record_arry = len(record_arry)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_record_arry - 1)


        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_arry[record_mid_ptr] <= record_val):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return (record_arry[record_left_ptr] if (record_left_ptr < len_record_arry) else (-1))
