class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of letters array #####
        len_letters = len(letters)

        ##### Record target value #####
        record_target = ord(target)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_letters - 1)


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-char matched conditions or not #####
            if (ord(letters[record_mid_ptr]) <= record_target):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = record_mid_ptr #Keep updating/overwriting

        ##### Check if the current indexed-char matched conditions or not #####
        if (record_left_ptr == (len_letters - 1)):
            if (ord(letters[record_left_ptr]) > record_target):
                return letters[record_left_ptr]
            
            return letters[0]

        return letters[record_left_ptr]
