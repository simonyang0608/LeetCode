class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of tasks array #####
        len_tasks = len(tasks)

        ##### Record array #####
        record_arry = [0 for _ in range(26)]

        ##### Record maximun summary counter #####
        record_max_cnter = 0

        ##### Maximun value summary counter #####
        max_val_cnter = 0


        #################################################
        #Greedy-based loop traversal with recorded array
        ##### Step 1: Record indexed-char with array #####
        for tasks_idx in range(len_tasks):
            record_arry[(ord(tasks[tasks_idx]) - 65)] += 1 #Keep updating/accumulating

            record_max_cnter = max(record_max_cnter, record_arry[(ord(tasks[tasks_idx]) - 65)]) #Keep updating/Overwriting

        ##### Step 2: Looped-traversal with recorded array #####
        for record_idx in range(26):

            ##### Check if the current summary counter is maximun or not #####
            if (record_arry[record_idx] == record_max_cnter):
                max_val_cnter += 1 #Keep updating/accumulating
            else:
                pass

        return max((((record_max_cnter - 1) * (n + 1)) + max_val_cnter), len_tasks)
