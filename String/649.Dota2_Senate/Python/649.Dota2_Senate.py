class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """
        #==============================#
        # Queue-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of senate string #####
        len_senate = len(senate)

        ##### Record queues (i.e. R, D) #####
        record_queue_r, record_queue_d = [], []


        ############################
        #Queue-based loop traversal
        ##### Step 1: Record indexes with queues #####
        for senate_idx in range(len_senate):

            ##### Check if the current indexed-char matched conditions or not #####
            if (senate[senate_idx] == 'R'):
                record_queue_r.append(senate_idx) #Keep updating/recording
            else:
                record_queue_d.append(senate_idx) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded queues #####
        while (record_queue_r and record_queue_d):

            ##### Check if the current index matched conditions or not ##### 
            if (record_queue_r[0] < record_queue_d[0]):
                record_queue_d.pop(0) #Keep updating/popped

                record_queue_r.append((record_queue_r[0] + len_senate)) #Keep updating/recording

                record_queue_r.pop(0) #Keep updating/popped
            
            else:
                record_queue_r.pop(0) #Keep updating/popped

                record_queue_d.append((record_queue_d[0] + len_senate)) #Keep updating/recording

                record_queue_d.pop(0) #Keep updating/popped
        
        return ("Radiant" if (record_queue_r) else "Dire")
