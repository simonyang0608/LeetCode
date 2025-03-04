class Solution(object):
    def maxScore(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums1)

        ##### Record array #####
        record_arry = []

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Record score #####
        record_score = 0

        ##### Result maximun score #####
        res_max_score = 0


        #################################################################
        #Heap/Priority-queue based loop traversal with sorted-operations
        ##### Step 1: Record indexed-values informations #####
        heapify(record_pq) #Update/Heapify

        for nums_idx in range(len_nums):
            record_arry.append([nums2[nums_idx], nums1[nums_idx]]) #Keep updating/recording

        ##### Step 2: Looped-traversal for the fixed-window size #####
        record_arry.sort(reverse = True) #Sorted-operations

        for record_idx in range(k):
            record_score += (record_arry[record_idx])[1] #Keep updating/accumulating

            heappush(record_pq, (record_arry[record_idx])[1]) #Keep updating/recording

        ##### Step 3: Looped-traversal for the remainings #####
        res_max_score = max(res_max_score, (record_score * (record_arry[(k - 1)])[0])) #Update/Overwrite

        for record_idx in range(k, len_nums):
            record_score -= record_pq[0] #Keep updating/reducing

            heappop(record_pq) #Keep updating/popped

            record_score += (record_arry[record_idx])[1] #Keep updating/accumulating

            heappush(record_pq, (record_arry[record_idx])[1]) #Keep updating/recording

            res_max_score = max(res_max_score, (record_score * (record_arry[record_idx])[0])) #Keep updating/overwriting

        return res_max_score
