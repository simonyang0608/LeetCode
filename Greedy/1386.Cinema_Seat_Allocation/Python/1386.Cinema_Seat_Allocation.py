class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of reservedSeats array #####
        len_reservedSeats = len(reservedSeats)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Bit-values (i.e. 2345, 4567, 6789) #####
        bit_2345, bit_4567, bit_6789 = 60, 240, 960

        ##### Total summary counter #####
        total_cnter = (2 * n)


        ####################################################
        #Greedy-based loop traversal with bit-manipulations
        ##### Step 1: Record indexed-values with dictionary/hashmap #####
        for reservedSeats_idx in range(len_reservedSeats):

            ##### Check if the current indexed-rows existed or not #####
            if ((reservedSeats[reservedSeats_idx])[0] not in record_dict):
                record_dict[(reservedSeats[reservedSeats_idx])[0]] = [(reservedSeats[reservedSeats_idx])[1]] #Keep updating/recording
            else:
                (record_dict[(reservedSeats[reservedSeats_idx])[0]]).append((reservedSeats[reservedSeats_idx])[1]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_key in record_dict:
            record_sum_val, record_cnter = 0, 0 #Record summary value, counter

            for record_val in record_dict[record_key]:
                record_sum_val |= (1 << record_val) #Keep uupdating/accumulating

            ##### Check if the current bit-manipulations matched conditions or not #####
            if ((record_sum_val & bit_2345)):
                record_cnter += 1 #Keep updating/accumulating
            else:
                pass

            if ((record_sum_val & bit_6789)):
                record_cnter += 1 #Keep updating/accumulating
            else:
                pass

            if ((not (record_sum_val & bit_4567)) and record_cnter):
                record_cnter = 1 #Keep updating/overwriting
            else:
                pass

            total_cnter -= record_cnter #Keep updating/reducing

        return total_cnter
