class Solution(object):
    def numsSameConsecDiff(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        #==================================#
        # Queue-based BFS traversal method #
        #==================================#

        ############
        #Initialize
        ##### Visit dictionary/hashmap #####
        visit_dict = {}

        ##### Result array #####
        res_arry = []


        ################################
        #Queue-based BFS loop traversal
        for digit_idx in range(1, 10):
            record_queue = [str(digit_idx)] #Record queue

            self.bfsTraversal(record_queue, visit_dict, res_arry, n, k) #BFS function call

        return res_arry


    def bfsTraversal(self, record_queue, visit_dict, res_arry, n, k):
        """
        :type record_queue: List[str]
        :type visit_dict: dict
        :type res_arry: List[int]
        :type n: int
        :type k: int
        :rtype: None, void
        """
        #====================================#
        # Queue-based BFS traversal function #
        #====================================#

        ####################
        #Whole process/flow
        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                record_str = record_queue.pop(0) #Record string

                ##### Check if the current string is visited or not #####
                if (record_str in visit_dict):
                    continue

                visit_dict[record_str] = True #Keep updating/recording

                ##### Check if the current string matched conditions or not #####
                if (len(record_str) >= n):
                    res_arry.append(int(record_str)) #Keep updating/recording

                    continue

                record_val = int(record_str[(-1)]) #Record value

                next_incr_val, next_decr_val = (record_val + k), (record_val - k) #Next value (i.e. increase, decrease)

                ##### Check if the next decrease value matched conditions or not #####
                if (next_decr_val >= 0):
                    record_queue.append((record_str + str(next_decr_val))) #Keep updating/recording
                else:
                    pass

                ##### Check if the next increase value matched conditions or not #####
                if (next_incr_val <= 9):
                    record_queue.append((record_str + str(next_incr_val))) #Keep updating/recording
                else:
                    pass
