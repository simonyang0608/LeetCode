class Solution(object):
    def possibleBipartition(self, n, dislikes):
        """
        :type n: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of dislikes array #####
        len_dislikes = len(dislikes)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Record array #####
        record_arry = [(-1) for _ in range(n)]


        ###########################################################################
        #Breath-first search based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for dislikes_idx in range(len_dislikes):
            curr_node, next_node = ((dislikes[dislikes_idx])[0] - 1), ((dislikes[dislikes_idx])[1] - 1) #Current, Next node

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

            ##### Check if the current node is visited or not #####
            if (record_arry[n_idx] != (-1)):
                continue

            record_arry[n_idx] = 0 #Keep updating/overwriting

            record_flag = self.bfsTraversal(root_child_dict, record_arry, n_idx) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (not record_flag):
                return False

        return True


    def bfsTraversal(self, root_child_dict, record_arry, record_node):
        """
        :type root_child_dict: dict
        :type record_arry: List[int]
        :type record_node: int
        :rtype: bool
        """
        #==============================================#
        # Breath-first search based traversal function #
        #==============================================#

        ############
        #Initialize
        record_queue = [record_node]

        ####################
        #Whole process/flow
        while (record_queue):
            curr_node = record_queue.pop(0) #Current node

            ##### Check if the current node existed or not #####
            if (curr_node in root_child_dict):
                for next_node in root_child_dict[curr_node]:

                    ##### Check if the next node is visited or not #####
                    if (record_arry[next_node] == (-1)):
                        record_arry[next_node] = (1 - record_arry[curr_node]) #Keep updating/overwriting

                        record_queue.append(next_node) #Keep updating/recording
                    
                    elif (record_arry[next_node] == record_arry[curr_node]):
                        return False
            else:
                pass

        return True
