class Solution(object):
    def minAnagramLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        #=======================================#
        # Array-counting based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        #####################################
        #Array-counting based loop traversal
        for s_idx in range(1, (len_s + 1)):

            ##### Check if the current length is dividable or not #####
            if ((len_s % s_idx)):
                continue

            ##### Check if it's the minimun concatenated-anagrams or not #####
            if (self.isConcateAnag(len_s, s, s_idx)):
                return s_idx

        return len_s


    def isConcateAnag(self, len_s, s, record_cnter):
        """
        :type len_s: int
        :type s: str
        :type record_cnter: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Record array #####
        record_arry = [0 for _ in range(26)]

        ##### Record string #####
        record_str = s[: record_cnter]


        ####################
        #Whole process/flow
        ##### Step 1: Looped-traversal for the fixed-window size #####
        for record_chr in record_str:
            record_arry[(ord(record_chr) - 97)] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal for the remainings #####
        for s_idx in range(record_cnter, len_s, record_cnter):
            sub_arry = [0 for _ in range(26)] #Sub-array #####

            record_str = s[s_idx: (s_idx + record_cnter)] #Keep updating/overwriting

            for record_chr in record_str:
                sub_arry[(ord(record_chr) - 97)] += 1 #Keep updating/recording

            ##### Check if the current array matched conditions or not #####
            if (sub_arry != record_arry):
                return False

        return True
