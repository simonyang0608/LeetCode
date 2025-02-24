class Solution(object):
    def asteroidCollision(self, asteroids):
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of asteroids array #####
        len_asteroids = len(asteroids)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result array #####
        res_arry = []


        ############################
        #Stack-based loop traversal
        while (record_trav_ptr < len_asteroids):
            record_val = asteroids[record_trav_ptr] #Record value

            ##### Check if the current indexed-value is less than 0 or not #####
            if (record_val > 0):
                res_arry.append(record_val) #Keep updating/recording

            elif ((not res_arry) or (res_arry[(-1)] < 0)):
                res_arry.append(record_val) #Keep updating/recording

            elif ((res_arry[(-1)] > 0) and (((-1) * record_val) >= res_arry[(-1)])):

                ##### Check if the current indexed-value matched conditions or not #####
                if (((-1) * record_val) == res_arry[(-1)]):
                    pass
                else:
                    record_trav_ptr -= 1 #Keep updating/traversing

                res_arry.pop() #Keep updating/popped

            record_trav_ptr += 1 #Keep updating/traversing

        return res_arry
