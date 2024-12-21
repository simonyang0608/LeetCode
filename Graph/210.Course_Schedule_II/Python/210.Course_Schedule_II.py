class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        #============================================#
        # Breath-first search based traversal method #
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

        ##### Result array #####
        res_arry = []


        ##############################################################
        #Breath-first search based loop traversal with recorded queue
        ##### Step 1: Record indexed-value with array, dictionary/hashmap #####
        for prerequisites_idx in range(len_prerequisites):
            record_key, record_value = (prerequisites[prerequisites_idx])[1], (prerequisites[prerequisites_idx])[0] #Record key, value

            ##### Check if the current key exsited or not #####
            if (record_key not in record_dict):
                record_dict[record_key] = [record_value] #Keep updating/recording
            else:
                (record_dict[record_key]).append(record_value) #Keep updating/recording

            record_arry[record_value] += 1 #Keep updating/accumulating

        ##### Step 2: Record indexed-value with queue #####
        for record_idx in range(numCourses):

            ##### Check if the current indexed-value matched conditions or not #####
            if (not record_arry[record_idx]):
                record_queue.append(record_idx) #Keep updating/recording
            else:
                pass

        ##### Step 3: Looped-traversal with recorded queue #####
        while (record_queue):
            len_queue = len(record_queue) #Update/Overwrite

            numCourses -= len_queue #Update/Reduce

            for _ in range(len_queue):
                record_idx = record_queue.pop(0) #Record index

                res_arry.append(record_idx) #Keep updating/recording

                ##### Check if the current index existed or not #####
                if (record_idx in record_dict):
                    for next_idx in record_dict[record_idx]:

                        ##### Check if thhe current indexed-value matched conditions or not #####
                        if (not record_arry[next_idx]):
                            continue

                        record_arry[next_idx] -= 1 #Keep updating/reducing

                        if (not record_arry[next_idx]):
                            record_queue.append(next_idx) #Keep updating/recording
                        else:
                            pass
                else:
                    pass

        return (res_arry if (not numCourses) else [])
