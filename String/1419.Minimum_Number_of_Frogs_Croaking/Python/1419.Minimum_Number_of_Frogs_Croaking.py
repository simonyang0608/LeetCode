class Solution(object):
    def minNumberOfFrogs(self, croakOfFrogs):
        """
        :type croakOfFrogs: str
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of croakOfFrogs array #####
        len_croakOfFrogs = len(croakOfFrogs)

        ##### Record dictionary/hashmap (i.e. char) #####
        record_dict = {'c': 0, 'r': 1, 'o': 2, 'a': 3, 'k': 4}

        ##### Record dictionary/hashmap (i.e. summary counter) #####
        record_dict_cnter = {}

        ##### Record frogs #####
        record_frog = 0

        ##### Result minimun summary counter #####
        res_min_cnter = 0


        ##############################
        #Hashmap-based loop traversal
        for croakOfFrogs_idx in range(len_croakOfFrogs):

            ##### Check if the current indexed-char existed or not #####
            if (croakOfFrogs[croakOfFrogs_idx] == 'c'):

                ##### Check if the current index existed or not #####
                if (record_dict[croakOfFrogs[croakOfFrogs_idx]] not in record_dict_cnter):
                    record_dict_cnter[record_dict[croakOfFrogs[croakOfFrogs_idx]]] = 1 #Keep updating/recording
                else:
                    record_dict_cnter[record_dict[croakOfFrogs[croakOfFrogs_idx]]] += 1 #Keep updating/recording

                record_frog += 1 #Keep updating/accumulating

                res_min_cnter = max(res_min_cnter, record_frog) #Keep updating/overwriting

            elif (croakOfFrogs[croakOfFrogs_idx] == 'k'):

                ##### Check if the current index existed or not #####
                if ((record_dict[croakOfFrogs[croakOfFrogs_idx]] - 1) not in record_dict_cnter):
                    return (-1)

                ##### Check if the previous summary counter is less than 0 or not #####
                if ((record_dict_cnter[(record_dict[croakOfFrogs[croakOfFrogs_idx]] - 1)] - 1) < 0):
                    return (-1)

                record_dict_cnter[(record_dict[croakOfFrogs[croakOfFrogs_idx]] - 1)] -= 1 #Keep updating/recording

                record_frog -= 1 #Keep updating/reducing

            else:
                ##### Check if the current index existed or not #####
                if ((record_dict[croakOfFrogs[croakOfFrogs_idx]] - 1) not in record_dict_cnter):
                    return (-1)

                ##### Check if the previous summary counter is less than 0 or not #####
                if ((record_dict_cnter[(record_dict[croakOfFrogs[croakOfFrogs_idx]] - 1)] - 1) < 0):
                    return (-1)

                record_dict_cnter[(record_dict[croakOfFrogs[croakOfFrogs_idx]] - 1)] -= 1 #Keep updating/recording

                ##### Check if the current index existed or not #####
                if (record_dict[croakOfFrogs[croakOfFrogs_idx]] not in record_dict_cnter):
                    record_dict_cnter[record_dict[croakOfFrogs[croakOfFrogs_idx]]] = 1 #Keep updating/recording
                else:
                    record_dict_cnter[record_dict[croakOfFrogs[croakOfFrogs_idx]]] += 1 #Keep updating/recording

        return (res_min_cnter if (not record_frog) else (-1))
