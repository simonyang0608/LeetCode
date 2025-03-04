class Solution(object):
    def minFlips(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        #=========================================#
        # Bit-manipulation based traversal method #
        #=========================================#

        ############
        #Initialize
        ##### Result minimun summary counter #####
        res_min_cnter = 0

        #######################################
        #Bit-manipulation based loop traversal
        for bit_idx in range(31, (-1), (-1)):
            record_bit_a = ((a >> bit_idx) & 1) #Record bit-a
            record_bit_b = ((b >> bit_idx) & 1) #Record bit-b
            record_bit_c = ((c >> bit_idx) & 1) #Record bit-c

            ##### Check if the current bit-a, b matched conditions or not #####
            if (record_bit_a):

                ##### Check if the current bit-b matched conditions or not #####
                if (record_bit_b):

                    ##### Check if the current bit-c matched conditions or not #####
                    if (record_bit_c):
                        pass
                    else:
                        res_min_cnter += 2 #Keep updating/accumulating
                else:
                    ##### Check if the current bit-c matched conditions or not #####
                    if (record_bit_c):
                        pass
                    else:
                        res_min_cnter += 1 #Keep updating/accumulating

            else:
                ##### Check if the current bit-b matched conditions or not #####
                if (record_bit_b):
                    ##### Check if the current bit-c matched conditions or not #####
                    if (record_bit_c):
                        pass
                    else:
                        res_min_cnter += 1 #Keep updating/accumulating
                else:
                    ##### Check if the current bit-c matched conditions or not #####
                    if (record_bit_c):
                        res_min_cnter += 1 #Keep updating/accumulating
                    else:
                        pass

        return res_min_cnter
