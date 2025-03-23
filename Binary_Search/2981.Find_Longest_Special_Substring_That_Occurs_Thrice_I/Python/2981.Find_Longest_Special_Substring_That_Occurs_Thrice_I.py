class Solution(object):
    def maximumLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_s - 2)


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) // 2) #Record middle pointer

            record_flag = self.occurThrice(len_s, s, record_mid_ptr) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (record_flag):
                record_left_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return ((-1) if (not record_left_ptr) else record_left_ptr)


    def occurThrice(self, len_s, s, record_val):
        """
        :type len_s: int
        :type s: str
        :type record_val: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {}

        ####################
        #Whole process/flow
        ##### Step 1: Record indexed-string with dictionary/hashmap #####
        for record_idx in range((len_s - record_val + 1)):
            record_str = s[record_idx: (record_idx + record_val)] #Record string

            ##### Check if the current indexed-string existed or not #####
            if (record_str not in record_dict):
                record_dict[record_str] = 1 #Keep updating/recording
            else:
                record_dict[record_str] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_key in record_dict:
            record_dict_cnter = {} #Record dictionary/hashmap (i.e. summary counter)

            for record_chr in record_key:

                ##### Check if the current indexed-char existed or not #####
                if (record_chr not in record_dict_cnter):
                    record_dict_cnter[record_chr] = True #Keep updating/recording
                else:
                    pass

            ##### Check if the current string is special or not #####
            if (len(record_dict_cnter) != 1):
                continue

            ##### Check if the current summary counter matched conditions or not #####
            if (record_dict[record_key] >= 3):
                return True

        return False
