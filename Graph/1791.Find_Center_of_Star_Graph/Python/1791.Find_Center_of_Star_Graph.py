class Solution(object):
    def findCenter(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: int
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result maximun edges #####
        res_max_edge = (-1)


        #######################################################################
        #One-pass record based loop traversal with recorded dictionary/hashmap
        for edges_idx in range(len_edges):
            main_node, sub_node = (edges[edges_idx])[0], (edges[edges_idx])[1] #Main, Sub node

            ##### Check if the current node existed or not #####
            if (main_node not in record_dict):
                record_dict[main_node] = 1 #Keep updating/recording
            else:
                record_dict[main_node] += 1 #Keep updating/recording

            ##### Check if the current edges is larger or not #####
            if (record_dict[main_node] > res_max_edge):
                res_max_edge = record_dict[main_node] #Keep updating/overwriting
                res_max_node = main_node #Keep updating/overwriting
            else:
                pass

            ##### Check if the current node existed or not #####
            if (sub_node not in record_dict):
                record_dict[sub_node] = 1 #Keep updating/recording
            else:
                record_dict[sub_node] += 1 #Keep updating/recording

            ##### Check if the current edges is larger or not #####
            if (record_dict[sub_node] > res_max_edge):
                res_max_edge = record_dict[sub_node] #Keep updating/overwriting
                res_max_node = sub_node #Keep updating/overwriting
            else:
                pass

        return res_max_node
