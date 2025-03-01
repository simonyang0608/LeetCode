class Solution(object):
    def smallestStringWithSwaps(self, s, pairs):
        """
        :type s: str
        :type pairs: List[List[int]]
        :rtype: str
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        #############
        #Iniitialize
        ##### Length of pairs array, s string #####
        len_pairs, len_s = len(pairs), len(s)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Visit dictionary/hashmap #####
        visit_dict = {}

        ##### Result array #####
        res_arry = list(s)


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record nodes informations with dictionary/hashmap #####
        for pairs_idx in range(len_pairs):
            curr_node, next_node = (pairs[pairs_idx])[0], (pairs[pairs_idx])[1] #Current, Next node

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
        for s_idx in range(len_s):

            ##### Check if the current node is visited or not #####
            if (s_idx in visit_dict):
                continue

            index_arry, char_arry = [], [] #Index, Char array

            self.dfsTraversal(s, root_child_dict, visit_dict, index_arry, char_arry, s_idx) #Recursion function call

            index_arry.sort() #Sorted operations

            char_arry.sort() #Sorted operations

            for record_idx in range(len(index_arry)):
                res_arry[index_arry[record_idx]] = char_arry[record_idx] #Keep updating/overwriting

        return ''.join(res_arry)

        
    def dfsTraversal(self, s, root_child_dict, visit_dict, index_arry, char_arry, record_node):
        """
        :type s: str
        :type root_child_dict: dict
        :type visit_dict: dict
        :type index_arry: List[int]
        :type char_arry: List[char]
        :type record_node: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (record_node in visit_dict): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        visit_dict[record_node] = True #Update/Record

        index_arry.append(record_node) #Update/Record

        char_arry.append(s[record_node]) #Update/Record

        ##### Check if the current node existed or not #####
        if (record_node in root_child_dict):
            for next_node in root_child_dict[record_node]:
                self.dfsTraversal(s, root_child_dict, visit_dict, index_arry, char_arry, next_node) #Recursion function call
