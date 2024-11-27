class Solution(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        """
        :type n: int
        :type headID: int
        :type manager: List[int]
        :type informTime: List[int]
        :rtype: int
        """
        #============================================#
        # Recursion-based DFS & BFS traversal method #
        #============================================#

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {}

        ###########################################################################
        #Recursion-based DFS & BFS loop traversal with recorded dictionary/hashmap
        for n_idx in range(n):

            ##### Check if the current indexed-value existed or not #####
            if (manager[n_idx] not in record_dict):
                record_dict[manager[n_idx]] = [[n_idx, informTime[n_idx]]] #Keep updating/recording
            else:
                (record_dict[manager[n_idx]]).append([n_idx, informTime[n_idx]]) #Keep updating/recording

        return self.dfsbfsTraversal(record_dict, (-1), 0) #Recursion function call


    def dfsbfsTraversal(self, record_dict, record_manager, record_time):
        """
        :type record_dict: dict
        :type record_manager: int
        :type record_time: int
        :rtype: int
        """
        #==============================================#
        # Recursion-based DFS & BFS traversal function #
        #==============================================#
        if (record_manager not in record_dict): #Issue/Boundary-case handling
            return record_time

        ############
        #Initialize
        ##### Result maximun time #####
        res_max_time = record_time

        ####################
        #Whole process/flow
        for [sub_employee, sub_time] in record_dict[record_manager]:

            tmp_time = self.dfsbfsTraversal(record_dict, sub_employee, (record_time + sub_time)) #Recursion function call

            ##### Check if the current time matched conditions or not #####
            if (tmp_time > res_max_time):
                res_max_time = tmp_time #Keep updating/overwriting
            else:
                pass

        return res_max_time
