class Solution(object):
    def totalCost(self, costs, k, candidates):
        """
        :type costs: List[int]
        :type k: int
        :type candidates: int
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of costs array #####
        len_costs = len(costs)

        ##### Record heap/priority-queues (i.e. left, right) #####
        record_pq_left, record_pq_right = [], []

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_costs - 1)

        ##### Result minimun costs #####
        res_min_costs = 0


        #####################################################################
        #Two-pointers based loop traversal with recorded heap/priority-queue
        heapify(record_pq_left) #Heapify (left-half)
        heapify(record_pq_right) #Heapify (right-half)

        for k_idx in range(k):
            while ((record_left_ptr <= record_right_ptr) and (len(record_pq_left) < candidates)):
                heappush(record_pq_left, [costs[record_left_ptr], record_left_ptr]) #Keep updating/recording

                record_left_ptr += 1 #Keep updating/traversing
            
            while ((record_right_ptr >= record_left_ptr) and (len(record_pq_right) < candidates)):
                heappush(record_pq_right, [costs[record_right_ptr], record_right_ptr]) #Keep updating/recording

                record_right_ptr -= 1 #Keep updating/traversing

            record_left_val = ((record_pq_left[0])[0] if (record_pq_left) else ((10 ** 5) + 1)) #Record left-half value
            record_right_val = ((record_pq_right[0])[0] if (record_pq_right) else ((10 ** 5) + 1)) #Record right-half value

            ##### Check if the right-half value is smaller or not #####
            if (record_right_val < record_left_val):
                res_min_costs += record_right_val #Keep updating/accumulating

                heappop(record_pq_right) #Keep updating/popped
            
            else:
                res_min_costs += record_left_val #Keep updating/accumulating

                heappop(record_pq_left) #Keep updating/popped

        return res_min_costs
