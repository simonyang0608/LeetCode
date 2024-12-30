class Solution(object):
    def removeDigit(self, number, digit):
        """
        :type number: str
        :type digit: str
        :rtype: str
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of number string #####
        len_number = len(number)

        ##### Record array #####
        record_arry = []


        #############################
        #Greedy-based loop traversal
        for number_idx in range(len_number):

            ##### Check if the current indexed-char matched conditions or not #####
            if (number[number_idx] == digit):
                record_arry.append((number[: number_idx] + number[(number_idx + 1): ])) #Keep updating/recording
            else:
                pass

        record_arry.sort() #Sorted operations

        return record_arry[(-1)]
