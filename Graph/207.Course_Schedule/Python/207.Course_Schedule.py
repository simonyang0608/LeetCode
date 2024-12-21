class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        #============================================#
        # Breath-first-search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of prerequisites array #####
        len_prerequisites = len(prerequisites)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record array #####
        record_arry = [0 for _ in range(numCourses)]

        ##### Record queue #####
        record_queue = []


        ###############################################################
        #Breath-first-search based loop traversal with recorded queue
        ##### Step 1: Record indexed-value with array, dictionary/hashmap #####
        for prerequisites_idx in range(len_prerequisites):
            record_key, record_value = (prerequisites[prerequisites_idx])[1], (prerequisites[prerequisites_idx])[0] #Record key, value

            ##### Check if the current indexed-value existed or not #####
            if (record_key not in record_dict):
                record_dict[record_key] = [record_value] #Keep updating/recording
            else:
                (record_dict[record_key]).append(record_value) #Keep updating/recording

            record_arry[record_value] += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal with recorded queue #####
        for record_idx in range(numCourses):

            ##### Check if the current indexed-value matched conditions or not #####
            if (not record_arry[record_idx]):
                record_queue.append(record_idx) #Keep updating/recording
            else:
                pass

        ##### Step 3: Post-process/Final completions #####
        while (record_queue):
            len_record_queue = len(record_queue) #Update/Overwrite

            numCourses -= len_record_queue #Update/Reduce

            for _ in range(len_record_queue):
                curr_val = record_queue.pop(0) #Current value

                ##### Check if the current indexed-value existed or not #####
                if (curr_val in record_dict):
                    for next_val in record_dict[curr_val]:

                        ##### Check if the next indexed-value existed or not #####
                        if (not record_arry[next_val]):
                            continue

                        record_arry[next_val] -= 1 #Keep updating/reducing

                        ##### Check if the current indexed-value matched conditions or not #####
                        if (not record_arry[next_val]):
                            record_queue.append(next_val) #Keep updating/recording
                        else:
                            pass
                else:
                    pass

        return (True if (not numCourses) else False)
