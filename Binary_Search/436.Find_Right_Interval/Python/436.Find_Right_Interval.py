class Solution(object):
    def findRightInterval(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[int]
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of intervals #####
        len_intervals = len(intervals)

        ##### Record dictionary/hashmap (i.e. index, right-interval) #####
        record_idx_map, record_rinterval_map = {}, {}

        ##### Record rightest edge/boundary #####
        record_rbound = (len_intervals - 1)

        ##### Sorted operations #####
        sort_intervals = sorted(intervals)

        ##### Result array #####
        res_arry = [(-1) for _ in range(len_intervals)]


        #####################################################################
        #Binary-search based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-position with dictionary/hashmap #####
        for intervals_idx in range(len_intervals):
            record_idx_map[(intervals[intervals_idx])[0]] = intervals_idx #Keep updating/recording

        ##### Step 2: Record minimized right-bound with dictionary/hashmap #####
        for intervals_idx in range(len_intervals):
            target = (sort_intervals[intervals_idx])[1] #Target value

            ##### Check if the current target matched conditions or not #####
            if (target > (sort_intervals[record_rbound])[0]):
                record_rinterval_map[(sort_intervals[intervals_idx])[0]] = (-1000001) #Keep updating/recording

                continue

            else:
                record_rinterval_map[(sort_intervals[intervals_idx])[0]] = self.binarySearch(intervals_idx, record_rbound, sort_intervals, target) #Keep updating/recording

        ##### Step 3: Looped-traversal with recorded dictionary, hashmap #####
        for intervals_idx in range(len_intervals):

            ##### Check if the current indexed-value conditions or not #####
            if (record_rinterval_map[(intervals[intervals_idx])[0]] == (-1000001)):
                continue

            res_arry[intervals_idx] = record_idx_map[record_rinterval_map[(intervals[intervals_idx])[0]]] #Keep updating/overwriting

        return res_arry


    def binarySearch(self, left_ptr, right_ptr, record_arry, target):
        """
        :type left_ptr: int
        :type right_ptr: int
        :type record_arry: List[List[int]]
        :type target: int
        :rtype: int
        """
        #========================================#
        # Binary-search based traversal function #
        #========================================#

        ####################
        #Whole process/flow
        while (left_ptr < right_ptr):
            mid_ptr = ((left_ptr + right_ptr) // 2) #Middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if ((record_arry[mid_ptr])[0] < target):
                left_ptr = (mid_ptr + 1) #Keep updating/overwriting
            else:
                right_ptr = mid_ptr #Keep updating/overwriting

        return (record_arry[left_ptr])[0]
