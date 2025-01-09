class Solution(object):
    def minMutation(self, startGene, endGene, bank):
        """
        :type startGene: str
        :type endGene: str
        :type bank: List[str]
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of bank array #####
        len_bank = len(bank)

        ##### Record visited dictionary/hashmap #####
        visit_dict = {}

        ##### Record queue #####
        record_queue = [[startGene, 0]]


        ##########################################
        #Breath-first search based loop traversal
        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                record_str, res_step = (record_queue[0])[0], (record_queue[0])[1] #Record, Result string, steps

                record_queue.pop(0) #Keep updating/popped

                ##### Check if the current string matched conditions or not #####
                if (record_str == endGene):
                    return res_step

                ##### Check if the current string is visited or not #####
                if (record_str in visit_dict):
                    continue

                visit_dict[record_str] = True #Keep updating/recording

                for bank_idx in range(len_bank):

                    ##### Check if the current differences of char matched conditions or not #####
                    if (self.difChar(record_str, bank[bank_idx]) == 1):
                        record_queue.append([bank[bank_idx], (res_step + 1)]) #Keep updating/recording
                    else:
                        pass

        return (-1)

        
    def difChar(self, record_str, bank_str):
        """
        :type record_str: str
        :type bank_str: str
        :rtype: int
        """

        ############
        #Initialize
        ##### Result summary counter #####
        res_cnter = 0

        ####################
        #Whole process/flow
        for gene_idx in range(8):

            ##### Check if the current char is different or not #####
            if (record_str[gene_idx] != bank_str[gene_idx]):
                res_cnter += 1 #Keep updating/accumulating
            else:
                pass

        return res_cnter
