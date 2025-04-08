class Solution(object):
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of answers array #####
        len_answers = len(answers)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counter #####
        res_cnter = 0


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for answers_idx in range(len_answers):
            record_val = answers[answers_idx] #Record value

            ##### Check if the current indexed-value existed or not #####
            if (record_val not in record_dict):
                record_dict[record_val] = 1 #Keep updating/recording
            else:
                record_dict[record_val] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_ref in record_dict:
            record_cnter = record_dict[record_ref] #Record summary counter

            record_quot, record_mod = (record_cnter // (record_ref + 1)), (record_cnter % (record_ref + 1)) #Record quotient, module

            ##### Check if the current module matched conditions or not #####
            if (record_mod):
                res_cnter += ((record_ref + 1) * (record_quot + 1)) #Keep updating/accumulating
            else:
                res_cnter += ((record_ref + 1) * record_quot) #Keep updating/accumulating

        return res_cnter
