class Solution(object):
    def asteroidsDestroyed(self, mass, asteroids):
        """
        :type mass: int
        :type asteroids: List[int]
        :rtype: bool
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of asteroids array #####
        len_asteroids = len(asteroids)

        ##### Record array #####
        record_arry = [mass]


        #############################
        #Greedy-based loop traversal
        asteroids.sort() #Sorted operations

        for asteroids_idx in range(len_asteroids):

            ##### Check if the current indexed-value matched conditions or not #####
            if (asteroids[asteroids_idx] > record_arry[(-1)]):
                return False

            record_arry.append((record_arry[(-1)] + asteroids[asteroids_idx])) #Keep updating/recording

        return True
