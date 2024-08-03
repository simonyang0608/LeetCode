class Solution(object):
    def addSpaces(self, s, spaces):
        """
        :type s: str
        :type spaces: List[int]
        :rtype: str
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#
        
        ############
        #Initialize
        ##### Length of s string, spaces array #####
        len_s, len_spaces = len(s), len(spaces)

        ##### Record traversal pointers (i.e. s, spaces) #####
        record_ptr_s, record_ptr_spaces = 0, 0

        ##### Result array #####
        res_arry = []


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-traversal for the whole spaces #####
        while (record_ptr_spaces < len_spaces):
            record_space = spaces[record_ptr_spaces] #Record space values

            while (record_ptr_s < record_space):
                res_arry.append(s[record_ptr_s]) #Keep updating/overwriting

                record_ptr_s += 1 #Keep updating/accumulating

            res_arry.append(" ") #Update/Add space

            record_ptr_spaces += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal for the remained-string #####
        while (record_ptr_s < len_s):
            res_arry.append(s[record_ptr_s]) #Keep updating/overwriting

            record_ptr_s += 1 #Keep updating/accumulating

        return (('').join(res_arry))
