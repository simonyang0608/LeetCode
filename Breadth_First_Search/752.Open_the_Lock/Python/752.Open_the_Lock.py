class Solution(object):
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of deadends array #####
        len_deadends = len(deadends)

        ##### Record queue #####
        record_queue = []

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result minimun steps #####
        res_min_step = 0


        ############################################################################
        #Breath-first search based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-string with dictionary/hashmap #####
        for deadends_idx in range(len_deadends):
            record_dict[deadends[deadends_idx]] = True #Keep updating/recording

        if ("0000" in record_dict): #Issue/Boundary-case handling
            return (-1)

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        record_dict["0000"] = True #Update/Record

        record_queue.append("0000") #Update/Record

        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                record_str = record_queue.pop(0) #Record string

                ##### Check if the current string reach target or not #####
                if (record_str == target):
                    return res_min_step

                for record_idx in range(4):
                    next_str1 = (record_str[: record_idx] + ("0" if (record_str[record_idx] == "9") else str((int(record_str[record_idx]) + 1))) + record_str[(record_idx + 1): ]) #Next string-1

                    next_str2 = (record_str[: record_idx] + ("9" if (record_str[record_idx] == "0") else str((int(record_str[record_idx]) - 1))) + record_str[(record_idx + 1): ]) #Next string-2

                    ##### Check if the current string existed or not #####
                    if (next_str1 not in record_dict):
                        record_dict[next_str1] = True #Keep updating/recording

                        record_queue.append(next_str1) #Keep updating/recording
                    else:
                        pass

                    if (next_str2 not in record_dict):
                        record_dict[next_str2] = True #Keep updating/recording

                        record_queue.append(next_str2) #Keep updating/recording
                    else:
                        pass

            res_min_step += 1 #Keep updating/accumulating

        return (-1)
