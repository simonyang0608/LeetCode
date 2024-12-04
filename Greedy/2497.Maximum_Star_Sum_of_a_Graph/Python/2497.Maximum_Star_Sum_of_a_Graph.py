class Solution(object):
    def maxStarSum(self, vals, edges, k):
        """
        :type vals: List[int]
        :type edges: List[List[int]]
        :type k: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#
        if (len(vals) == 1): #Issue/Boundary-case handling
            return vals[0]

        ############
        #Initialize
        ##### Length of array (i.e. values, edges) #####
        len_vals, len_edges = len(vals), len(edges)

        ##### Record dictionary/hashmap #####
        record_dict = {vals_idx: [] for vals_idx in range(len_vals)}

        ##### Result summary counter #####
        res_max_cnter = max(vals)


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        for edges_idx in range(len_edges):
            main_node, sub_node = (edges[edges_idx])[0], (edges[edges_idx])[1] #Main, Sub-node

            (record_dict[main_node]).append(vals[sub_node]) #Keep updating/recording
            (record_dict[sub_node]).append(vals[main_node]) #Keep updating/recording

        for node in record_dict:

            ##### Check if the current edges existed or not #####
            if (not record_dict[node]):
                continue

            record_arry = sorted((sub_wgt for sub_wgt in record_dict[node] if (sub_wgt > 0)), reverse = True) #Record sorted array

            res_max_cnter = max(res_max_cnter, (vals[node] + sum(record_arry[: k]))) #Keep updating/overwriting

        return res_max_cnter
