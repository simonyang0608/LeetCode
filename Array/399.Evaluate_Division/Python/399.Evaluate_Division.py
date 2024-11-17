class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        #==================================#
        # DFS & BFS based traversal method #
        #==================================#

        ############
        #Initialize
        ##### Length of equations, queries #####
        len_equal = len(equations)
        len_queries = len(queries)

        ##### Record, Traversal dictionary/hashmap #####
        record_dict = {}
        record_trav_dict = {}

        ##### Result array #####
        res_arry = []


        #################################################################
        #DFS & BFS based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-elements with dictionary/hashmap #####
        for equal_idx in range(len_equal):
            record_equation = equations[equal_idx] #Record equation

            ##### Check if the current indexed-element existed or not #####
            if (record_equation[0] not in record_dict):
                record_dict[record_equation[0]] = [[record_equation[1], values[equal_idx]]] #Keep updating/recording
            else:
                (record_dict[record_equation[0]]).append([record_equation[1], values[equal_idx]]) #Keep updating/recording

            if (record_equation[1] not in record_dict):
                record_dict[record_equation[1]] = [[record_equation[0], (1. / values[equal_idx])]] #Keep updating/recording
            else:
                (record_dict[record_equation[1]]).append([record_equation[0], (1. / values[equal_idx])]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary #####
        for queries_idx in range(len_queries):
            record_query = queries[queries_idx] #Record query

            res_arry.append(self.dfsbfsTraversal(record_dict, record_query[0], record_query[1], 1., record_trav_dict)) #Recursion function call

            record_trav_dict.clear() #Reset

        return res_arry


    def dfsbfsTraversal(self, record_dict, start_query, end_query, res_scl, record_trav_dict):
        """
        :type record_dict: dict
        :type start_query: char
        :type end_query: char
        :type res_scl: float
        :type record_trav_dict: dict
        :rtype: float
        """
        #====================================#
        # DFS & BFS based traversal function #
        #====================================#
        if ((start_query not in record_dict) or (end_query not in record_dict)): #Issue/Boundary-case handling
            return (-1.)

        if (start_query == end_query): #Issue/Boundary-case handling
            return res_scl
            
        ####################
        #Whole process/flow
        record_trav_dict[start_query] = True #Update/Record

        for [tmp_end_query, tmp_scl] in record_dict[start_query]:

            ##### Check if the current query matched conditions or not #####
            if (tmp_end_query not in record_trav_dict):
                res = self.dfsbfsTraversal(record_dict, tmp_end_query, end_query, (res_scl * tmp_scl), record_trav_dict) #Recursion function call
                if (res != (-1.)):
                    return res

        return (-1.)
