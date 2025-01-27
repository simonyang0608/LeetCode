class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of arrays (i.e. difficulty, worker) #####
        len_difficulty, len_worker = len(difficulty), len(worker)

        ##### Record array #####
        record_arry = []

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record maximun value #####
        record_max_val = 0

        ##### Result maximun summary value #####
        res_max_sum = 0


        ####################################################
        #Greedy-based loop traversal with sorted operations
        ##### Step 1: Record tasks informations with array #####
        for difficulty_idx in range(len_difficulty):
            record_arry.append((difficulty[difficulty_idx], profit[difficulty_idx])) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        record_arry.sort() #Sorted operations
        worker.sort() #Sorted operations

        for worker_idx in range(len_worker):
            while ((record_trav_ptr < len_difficulty) and (worker[worker_idx] >= (record_arry[record_trav_ptr])[0])):
                record_max_val = max(record_max_val, (record_arry[record_trav_ptr])[1]) #Record maximun value

                record_trav_ptr += 1 #Keep updating/traversing

            res_max_sum += record_max_val #Keep updating/accumulating

        return res_max_sum
