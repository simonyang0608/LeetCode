class Solution(object):
    def minCostConnectPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        #============================#
        # Kruskal's traversal method #
        #============================#

        ############
        #Initialize
        ##### Length of points #####
        len_points = len(points)

        ##### Record array #####
        record_arry = []

        ##### Record rank array #####
        record_rank_arry = [1 for _ in range(len_points)]

        ##### Root-Child dictionary/hashmap #####
        root_child_dict = {}

        ##### Record edges summary value #####
        record_edge_sum = 0

        ##### Result minimun summary value #####
        res_min_sum = 0


        ##################################################################
        #Kruskal's loop traversal with recorded array, dictionary/hashmap
        ##### Step 1: Record root, nodes value with array, dictionary/hashmap #####
        for points_idx in range(len_points):
            for next_idx in range((points_idx + 1), len_points):
                record_dist_diff = (abs((points[points_idx])[0] - ((points[next_idx])[0])) + abs((points[points_idx])[1] - ((points[next_idx])[1]))) #Record distance difference

                record_arry.append([record_dist_diff, points_idx, next_idx]) #Keep updating/recording

            root_child_dict[points_idx] = points_idx #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded array, dictionary/hashmap #####
        record_arry.sort() #Sorted operations

        for record_idx in range(len(record_arry)):
            record_mroot_1 = self.findRoot(root_child_dict, (record_arry[record_idx])[1]) #Record main-root 1
            record_mroot_2 = self.findRoot(root_child_dict, (record_arry[record_idx])[2]) #Record main-root 2

            ##### Check if the current root has the same major root or not #####
            if (record_mroot_1 == record_mroot_2):
                continue

            self.Union(root_child_dict, record_rank_arry, record_mroot_1, record_mroot_2) #Union function call

            res_min_sum += (record_arry[record_idx])[0] #Keep updating/accumulating

            record_edge_sum += 1 #Keep updating/accumulating

            ##### Check if the current edges exceed number or not #####
            if (record_edge_sum >= (len_points - 1)):
                break

        return res_min_sum


    def findRoot(self, root_child_dict, record_root_val):
        """
        :type root_child_dict: dict
        :type record_root_val: int
        :rtype: int
        """
        ####################
        #Whole process/flow
        ##### Check if the current root points to its major root or not #####
        if (root_child_dict[record_root_val] != record_root_val):
            root_child_dict[record_root_val] = self.findRoot(root_child_dict, root_child_dict[record_root_val]) #Recursion function call

        return root_child_dict[record_root_val]
        

    def Union(self, root_child_dict, record_rank_arry, record_mroot_1, record_mroot_2):
        """
        :type root_child_dict: dict
        :type record_rank_arry: List[int]
        :type record_mroot_1: int
        :type record_mroot_2: int
        :rtype: None, void
        """
        ####################
        #Whole process/flow
        ##### Check which root rank is larger #####
        if (record_rank_arry[record_mroot_1] > record_rank_arry[record_mroot_2]):
            root_child_dict[record_mroot_2] = record_mroot_1 #Keep updating/overwriting

            record_rank_arry[record_mroot_1] += 1 #Keep updating/accumulating
        else:
            root_child_dict[record_mroot_1] = record_mroot_2 #Keep updating/overwriting

            record_rank_arry[record_mroot_2] += 1 #Keep updating/accumulating
