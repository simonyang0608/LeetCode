class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        #==========================================#
        # Bit-manipulations based traversal method #
        #==========================================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = [0, 1]

        ########################################
        #Bit-manipulations based loop traversal
        for n_idx in range(2, (n + 1)):
            res_arry.extend(res_arry[:: (-1)]) #Result array

            record_length = len(res_arry) #Record length

            for record_idx in range((record_length - 1), (((1 << n_idx) >> 1) - 1), (-1)):
                res_arry[record_idx] = ((1 << (n_idx - 1)) | res_arry[record_idx]) #Keep updating/overwriting

        return res_arry
