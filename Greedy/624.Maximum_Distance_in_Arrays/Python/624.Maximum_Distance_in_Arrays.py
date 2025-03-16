class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of arrays #####
        len_arrays = len(arrays)

        ##### Record values (i.e. maximun, minimun) #####
        record_max_val, record_min_val = (((-1) * (10 ** 4)) - 1), ((10 ** 4) + 1)

        ##### Record indexes (i.e. maximun, minimun) #####
        record_max_idx, record_min_idx = (-1), (-1)


        ########################
        #Greedy-based traversal
        ##### Step 1: Looped-traversal for the first-round #####
        for arrays_idx in range(len_arrays):

            ##### Check if the current indexed-value is minimun or not #####
            if ((arrays[arrays_idx])[0] < record_min_val):
                record_min_idx = arrays_idx #Keep updating/overwriting

                record_min_val = (arrays[arrays_idx])[0] #Keep updating/overwriting
            else:
                pass

            ##### Check if the current indexed-value is maximun or not #####
            if ((arrays[arrays_idx])[(-1)] > record_max_val):
                record_max_idx = arrays_idx #Keep updating/overwriting

                record_max_val = (arrays[arrays_idx])[(-1)] #Keep updating/overwriting
            else:
                pass

        if (record_min_idx != record_max_idx): #Issue/Boundary-case handling
            return (record_max_val - record_min_val)

        ##### Step 2: Looped-traversal for the final-round #####
        next_max_val, next_min_val = (((-1) * (10 ** 4)) - 1), ((10 ** 4) + 1) #Next values (i.e. maximun, minimun)

        for arrays_idx in range(len_arrays):

            ##### Check if the current index matched conditions or not #####
            if (arrays_idx == record_max_idx):
                continue

            next_max_val = max(next_max_val, (arrays[arrays_idx])[(-1)]) #Keep updating/overwriting
            next_min_val = min(next_min_val, (arrays[arrays_idx])[0]) #Keep updating/overwriting

        res_dist1, res_dist2 = (record_max_val - next_min_val), (next_max_val - record_min_val) #Result distances (i.e. 1st, 2nd)

        return (res_dist1 if (res_dist1 > res_dist2) else res_dist2)
