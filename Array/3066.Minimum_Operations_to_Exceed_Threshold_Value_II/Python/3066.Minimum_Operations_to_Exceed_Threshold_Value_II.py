class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Update/Heapify nums array #####
        heapify(nums)

        ##### Result minimun operations #####
        res_min_oprs = 0


        ##########################################
        #Heap/Priority-queue based loop traversal
        while (len(nums) >= 2):
            record_min1 = heappop(nums) #Record minimun value-1

            ##### Check if the current minimun value matched conditions or not #####
            if (record_min1 >= k):
                break

            record_min2 = heappop(nums) #Record minimun value-2

            heappush(nums, ((min(record_min1, record_min2) * 2) + max(record_min1, record_min2))) #Keep updating/recording

            res_min_oprs += 1 #Keep updating/accumulating

        return res_min_oprs
