class Solution(object):
    def findLeastNumOfUniqueInts(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record heap/priority-queue #####
        record_pq = []


        ###########################################################################
        #Heap/Priority-queue based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-values informations with dictionary/hashmap #####
        heapify(record_pq) #Update/Heapify

        for arr_idx in range(len_arr):

            ##### Check if the current indexed-value existed or not #####
            if (arr[arr_idx] not in record_dict):
                record_dict[arr[arr_idx]] = 1 #Keep updating/recording
            else:
                record_dict[arr[arr_idx]] += 1 #Keep updating/recording
        
        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_key in record_dict:
            heappush(record_pq, record_dict[record_key]) #Keep updating/recording

        while (k > 0):

            ##### Check if the current queued-value matched conditions or not #####
            if (record_pq[0] > k):
                break

            k -= record_pq[0] #Keep updating/reducing

            heappop(record_pq) #Keep updating/popped

        return len(record_pq)
