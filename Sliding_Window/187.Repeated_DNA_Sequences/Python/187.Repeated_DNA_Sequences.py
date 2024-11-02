class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)
        len_s -= 9

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result array #####
        res_arry = []


        #####################################
        #Sliding-window based loop traversal
        for s_idx in range(len_s):
            record_str = s[s_idx: (s_idx + 10)] #Record string

            ##### Check if the current string exists or not #####
            if (record_str not in record_dict):
                record_dict[record_str] = 1 #Keep updating/recording
            else:
                if (record_dict[record_str] < 2):
                    res_arry.append(record_str) #Keep updating/recording

                    record_dict[record_str] += 1 #Keep updating/accumulating

                else:
                    pass

        return res_arry
