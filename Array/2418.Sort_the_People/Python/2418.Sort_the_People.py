class Solution(object):
    def sortPeople(self, names, heights):
        """
        :type names: List[str]
        :type heights: List[int]
        :rtype: List[str]
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of names array #####
        len_names = len(names)

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Result array #####
        res_arry = []


        ##########################################
        #Heap/Priority-queue based loop traversal
        ##### Step 1: Record personal informations with heap/priority-queue #####
        heapify(record_pq) #Update/Heapify

        for names_idx in range(len_names):
            heappush(record_pq, [((-1) * heights[names_idx]), names[names_idx]]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded heap/priority-queue #####
        while (record_pq):
            res_arry.append((record_pq[0])[1]) #Keep updating/recording

            heappop(record_pq) #Keep updating/popped

        return res_arry
