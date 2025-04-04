class Solution(object):
    def gardenNoAdj(self, n, paths):
        """
        :type n: int
        :type paths: List[List[int]]
        :rtype: List[int]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of paths array #####
        len_paths = len(paths)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Result array #####
        res_arry = [0 for _ in range(n)]


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes information with dictionary/hashmap #####
        for paths_idx in range(len_paths):
            curr_node, next_node = ((paths[paths_idx])[0] - 1), ((paths[paths_idx])[1] - 1) #Current, Next node

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [next_node] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append(next_node) #Keep updating/recording

            ##### Check if the next node existed or not #####
            if (next_node not in root_child_dict):
                root_child_dict[next_node] = [curr_node] #Keep updating/recording
            else:
                (root_child_dict[next_node]).append(curr_node) #Keep updating/recording
        
        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for n_idx in range(n):
            color_arry = [False for _ in range(5)] #Color array

            ##### Check if the current node existed or not #####
            if (n_idx in root_child_dict):
                for next_node in root_child_dict[n_idx]:
                    color_arry[res_arry[next_node]] = True #Keep updating/recording
            else:
                pass

            for color_idx in range(4, 0, (-1)):

                ##### Check if the current indexed-color matched conditions or not #####
                if (not color_arry[color_idx]):
                    res_arry[n_idx] = color_idx #Keep updating/overwriting
                else:
                    pass

        return res_arry
