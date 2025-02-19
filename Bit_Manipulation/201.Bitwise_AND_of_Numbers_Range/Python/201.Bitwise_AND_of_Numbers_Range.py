class Solution(object):
    def rangeBitwiseAnd(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        #===============================================#
        # Bit-wise manipulations based traversal method #
        #===============================================#

        ############
        #Initialize
        ##### Result value #####
        res_val = 0

        #############################################
        #Bit-wise manipulations based loop traversal
        for record_idx in range(31, (-1), (-1)):
            record_bit_val = (1 << record_idx) #Record bit-value

            ##### Check if the current bit-value matched conditions or not #####
            if ((record_bit_val & left) == (record_bit_val & right)):

                ##### Check if the current value is one or zero #####
                if ((record_bit_val & left)):
                    res_val |= record_bit_val #Keep updating/overwriting
                else:
                    pass

            else:
                break

        return res_val
