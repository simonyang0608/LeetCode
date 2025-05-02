class Solution(object):
    def baseUnitConversions(self, conversions):
        """
        :type conversions: List[List[int]]
        :rtype: List[int]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of conversions array #####
        len_conversions = len(conversions)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Record node, module #####
        record_node, record_module = 0, ((10 ** 9) + 7)

        ##### Result array #####
        res_arry = [1 for _ in range((len_conversions + 1))]


        ######################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for conversions_idx in range(len_conversions):
            curr_node = (conversions[conversions_idx])[0] #Current node

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [((conversions[conversions_idx])[1], (conversions[conversions_idx])[2])] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append(((conversions[conversions_idx])[1], (conversions[conversions_idx])[2])) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        self.dfsTraversal(root_child_dict, record_node, record_module, 1, res_arry) #Recursion function call

        return res_arry


    def dfsTraversal(self, root_child_dict, record_node, record_module, record_prod, res_arry):
        """
        :type root_child_dict: dict
        :type record_node: int
        :type record_module: int
        :type record_prod: long long
        :type res_arry: List[int]
        :rtype: None, void
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ####################
        #Whole process/flow
        ##### Check if the current node existed or not #####
        if (record_node in root_child_dict):
            for (next_node, sub_prod) in root_child_dict[record_node]:
                next_prod = (((record_prod % record_module) * sub_prod) % record_module) #Next product value

                res_arry[next_node] = next_prod #Keep updating/overwriting

                self.dfsTraversal(root_child_dict, next_node, record_module, next_prod, res_arry) #Recursion function call
        else:
            pass

        return
