class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):

        ############
        #Initialize
        ##### Result value #####
        res_val = 0

        #############################################
        #Bit-wise manipulations based loop traversal
        for record_idx in range(31, (-1), (-1)):
            res_val |= ((1 << (31 - record_idx)) if ((1 << record_idx) & n) else 0) #Keep updating/overwriting

        return res_val
        
