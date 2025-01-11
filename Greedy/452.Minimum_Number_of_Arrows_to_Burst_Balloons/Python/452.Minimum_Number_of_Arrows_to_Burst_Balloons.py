class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of points array #####
        len_points = len(points)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result summary counter #####
        res_cnter = 0


        #############################
        #Greedy-based loop traversal
        sort_points = sorted(points, key = lambda point: point[1]) #Sorted operations

        while (record_trav_ptr < len_points):
            end_val = (sort_points[record_trav_ptr])[1] #End-value

            res_cnter += 1 #Keep updating/accumulating

            while (((record_trav_ptr + 1) < len_points) and ((sort_points[(record_trav_ptr + 1)])[0] <= end_val)):
                record_trav_ptr += 1 #Keep updating/traversing

            record_trav_ptr += 1 #Keep updating/traversing

        return res_cnter
