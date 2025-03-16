class Solution(object):
    def maxJump(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of stones array #####
        len_stones = len(stones)

        ##### Record traversal pointers #####
        record_trav_ptr1, record_trav_ptr2 = 0, 1

        ##### Result maximun distance #####
        res_max_dist = (stones[record_trav_ptr2] - stones[record_trav_ptr1])


        #############################
        #Greedy-based loop traversal
        ##### Step 1: Looped-traversal for the first-jump #####
        while ((record_trav_ptr1 + 2) < len_stones):
            res_max_dist = max(res_max_dist, (stones[(record_trav_ptr1 + 2)] - stones[record_trav_ptr1])) #Keep updating/overwriting

            record_trav_ptr1 += 2 #Keep updating/traversing

        if (record_trav_ptr1 < (len_stones - 1)):
            res_max_dist = max(res_max_dist, (stones[(-1)] - stones[record_trav_ptr1])) #Update/Overwrite
        else:
            pass

        ##### Step 2: Looped-traversal for the second-jump #####
        while ((record_trav_ptr2 + 2) < len_stones):
            res_max_dist = max(res_max_dist, (stones[(record_trav_ptr2 + 2)] - stones[record_trav_ptr2])) #Keep updating/overwriting

            record_trav_ptr2 += 2 #Keep updating/traversing

        if (record_trav_ptr2 < (len_stones - 1)):
            res_max_dist = max(res_max_dist, (stones[(-1)] - stones[record_trav_ptr2])) #Update/Overwrite
        else:
            pass

        return res_max_dist
