class Solution(object):
    def canReach(self, arr, start):
        """
        :type arr: List[int]
        :type start: int
        :rtype: bool
        """
        #==================================#
        # Queue-based BFS traversal method #
        #==================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record queue #####
        record_queue = [start]

        ##### Record dictionary/hashmap #####
        record_dict = {start: True}


        #################################################################
        #Queue-based BFS loop traversal with recorded dictionary/hashmap
        while (record_queue):
            curr_idx = record_queue.pop(0) #Current indexes

            ##### Check if the current indexes matched conditions or not #####
            if (not arr[curr_idx]):
                return True

            prev_idx, next_idx = (curr_idx - arr[curr_idx]), (curr_idx + arr[curr_idx]) #Previous, Next indexes

            ##### Check if the previous indexes matched conditions or not #####
            if ((prev_idx >= 0) and (prev_idx not in record_dict)):
                record_queue.append(prev_idx) #Keep updating, recording

                record_dict[prev_idx] = True #Keep updating, recording
            else:
                pass

            ##### Check if the next indexes matched conditions or not #####
            if ((next_idx < len_arr) and (next_idx not in record_dict)):
                record_queue.append(next_idx) #Keep updating, recording

                record_dict[next_idx] = True #Keep updating, recording
            else:
                pass

        return False
