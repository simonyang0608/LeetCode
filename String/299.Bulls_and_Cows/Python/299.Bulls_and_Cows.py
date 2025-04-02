class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of secret string #####
        len_secret = len(secret)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counters (i.e. A, B) #####
        res_cnter_a, res_cnter_b = 0, 0


        #############################################################
        #Hashmap-based loop traversal with recorded summary counters
        ##### Step 1: Record indexed-char information with dictionary/hashmap #####
        for secret_idx in range(len_secret):

            ##### Check if the current indexed-char existed or not #####
            if (secret[secret_idx] not in record_dict):
                record_dict[secret[secret_idx]] = 1 #Keep updating/recording
            else:
                record_dict[secret[secret_idx]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for guess_idx in range(len_secret):

            ##### Check if the current indexed-char matched conditions or not #####
            if (secret[guess_idx] == guess[guess_idx]):
                record_dict[guess[guess_idx]] -= 1 #Keep updating/reducing
        
                res_cnter_a += 1 #Keep updating/accumulating
            else:
                pass

        for guess_idx in range(len_secret):

            ##### Check if the current indexed-char matched conditions or not #####
            if (secret[guess_idx] == guess[guess_idx]):
                continue

            ##### Check if the current indexed-char existed or not #####
            if (guess[guess_idx] in record_dict):
                record_dict[guess[guess_idx]] -= 1 #Keep updating/reducing

                ##### Check if the current summary counter matched conditions or not #####
                if (record_dict[guess[guess_idx]] >= 0):
                    res_cnter_b += 1 #Keep updating/accumulating
                else:
                    pass
            else:
                pass

        return (str(res_cnter_a) + 'A' + str(res_cnter_b) + 'B')
