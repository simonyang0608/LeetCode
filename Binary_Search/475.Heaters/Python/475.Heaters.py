class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. houses, heaters) #####
        len_houses, len_heaters = len(houses), len(heaters)

        ##### Record minimun radius #####
        record_min_radius = [((10 ** 9) + 3)]

        ##### Result minimun radius #####
        res_min_radius = 0


        ####################################
        #Binary-search based loop traversal
        houses.sort() #Sorted operations
        heaters.sort() #Sorted operations

        for houses_idx in range(len_houses):
            self.binarySearch(heaters, houses[houses_idx], record_min_radius) #Binary-search function cal

            res_min_radius = max(res_min_radius, record_min_radius[0]) #Keep updating/overwriting

            record_min_radius[0] = ((10 ** 9) + 3) #Keep updating/overwriting

        return res_min_radius


    def binarySearch(self, heaters, record_val, record_min_radius):
        """
        :type heaters: List[int]
        :type record_val: int
        :type record_min_radius: List[int]
        :rtype: None, void
        """

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(heaters) - 1)

        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (heaters[record_mid_ptr] < record_val):
                record_min_radius[0] = min(record_min_radius[0], (record_val - heaters[record_mid_ptr])) #Keep updating/overwriting

                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_min_radius[0] = min(record_min_radius[0], (heaters[record_mid_ptr] - record_val)) #Keep updating/overwriting

                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
