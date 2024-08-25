class Solution(object):
    def minimumFuelCost(self, roads, seats):
        """
        :type roads: List[List[int]]
        :type seats: int
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not roads): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Length of roads array #####
        len_roads = len(roads)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result array #####
        res_arry = [0]


        ####################################################################
        #Recursion-based DFS lop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for roads_idx in range(len_roads):
            main_node_val, sub_node_val = (roads[roads_idx])[0], (roads[roads_idx])[1] #Main, Sub-node value

            ##### Check if the current node-value existed or not #####
            if (main_node_val not in record_dict):
                record_dict[main_node_val] = [sub_node_val] #Keep updating/recording
            else:
                (record_dict[main_node_val]).append(sub_node_val) #Keep updating/recording

            if (sub_node_val not in record_dict):
                record_dict[sub_node_val] = [main_node_val] #Keep updating/recording
            else:
                (record_dict[sub_node_val]).append(main_node_val) #Keep updating/recording


        ##### Step 2: Looped-traversal with recorded dictionary #####
        res_people = self.dfsTraversal(record_dict, seats, 0, None, res_arry) #Recursion function call

        return res_arry[0]


    def dfsTraversal(self, record_dict, seats, node_val, prev_node_val, res_arry):
        """
        :type record_dict: dict
        :type seats: int
        :type node_val: int
        :type prev_node_val: int
        :type res_arry: List[int]
        :rtype: int
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ############
        #Initialize
        ##### Result people/repersentations #####
        res_people = 1

        ####################
        #Whole process/flow
        for sub_val in record_dict[node_val]:

            ##### Check if the current node value is previous or not #####
            if (sub_val == prev_node_val):
                continue
            else:
                res_people += self.dfsTraversal(record_dict, seats, sub_val, node_val, res_arry) #Recursion function call

        ##### Check if the current node value is capital type or not #####
        if (node_val != 0):

            ##### Check if the current divisions matched conditions or not #####
            if ((res_people % seats)):
                res_arry[0] += ((res_people // seats) + 1) #Update/Accumulate
            else:
                res_arry[0] += (res_people // seats) #Update/Accumulate
        else:
            pass

        return res_people
