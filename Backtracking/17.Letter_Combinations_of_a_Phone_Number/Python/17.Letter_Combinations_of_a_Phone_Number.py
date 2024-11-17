class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        #===================================#
        # Back-track based traversal method #
        #===================================#
        if (not digits): #Issue/Boundary-case handling
            return []

        ############
        #Initialize
        ##### Length of digits ##### 
        len_digits = len(digits)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        record_dict["2"] = ["a", "b", "c"]
        record_dict["3"] = ["d", "e", "f"]
        record_dict["4"] = ["g", "h", "i"]
        record_dict["5"] = ["j", "k", "l"]
        record_dict["6"] = ["m", "n", "o"]
        record_dict["7"] = ["p", "q", "r", "s"]
        record_dict["8"] = ["t", "u", "v"]
        record_dict["9"] = ["w", "x", "y", "z"]

        ##### Record array #####
        record_arry = record_dict[digits[0]]

        ##### Result array #####
        res_arry = []


        ##################################################################
        #Back-track based loop traversal with recorded dictionary/hashmap
        for char in record_arry:
            self.backtrackTraversal(len_digits, digits, 1, record_dict, char, res_arry) #Recursion function call

        return res_arry


    def backtrackTraversal(self, len_digits, digits, digits_idx, record_dict, record_str, res_arry):
        """
        :type len_digits: int
        :type digits: str
        :type digits_idx: int
        :type record_dict: dict
        :type record_str: str
        :type res_arry: List[str]
        :rtype: None, void
        """
        #=====================================#
        # Back-track based traversal function #
        #=====================================#
        if (digits_idx >= len_digits): #Issue, Boundary-case handling
            res_arry.append(record_str) #Update/Record

            return

        ############
        #Initialize
        ##### Record array #####
        record_arry = record_dict[digits[digits_idx]]

        ####################
        #Whole process/flow
        for char in record_arry:
            self.backtrackTraversal(len_digits, digits, (digits_idx + 1), record_dict, (record_str + char), res_arry) #Recursion function call
