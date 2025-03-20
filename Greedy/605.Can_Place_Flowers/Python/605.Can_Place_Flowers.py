class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of flowerbed array #####
        len_flowerbed = len(flowerbed)

        #############################
        #Greedy-based loop traversal
        if (len_flowerbed <= 1): #Issue/Boundary-case handling
            if (flowerbed[0]):
                if (n <= 0):
                    return True
                
                return False
            else:
                if (n <= 1):
                    return True

                return False

        ##### Check if the first indexed-value matched conditions or not #####
        if ((not flowerbed[0]) and (not flowerbed[1])):
            flowerbed[0] = 1 #Update/Overwrite

            n -= 1 #Update/Reduce
        else:
            pass

        ##### Check if the last indexed-value matched conditions or not #####
        if ((not flowerbed[(-1)]) and (not flowerbed[(-2)])):
            flowerbed[(-1)] = 1 #Update/Overwrite

            n -= 1 #Update/Reduce
        else:
            pass

        for flowerbed_idx in range(1, (len_flowerbed - 1)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (flowerbed[flowerbed_idx]):
                continue

            if ((not flowerbed[(flowerbed_idx - 1)]) and (not flowerbed[(flowerbed_idx + 1)])):
                flowerbed[flowerbed_idx] = 1 #Keep updating/overwriting

                n -= 1 #Keep updating/reducing
            else:
                pass

        return (True if (n <= 0) else False)
