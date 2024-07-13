class Solution(object):
    def findCircleNum(self, isConnected):
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_columns = len(isConnected), len(isConnected[0])

        ##### Record traversed/visited array #####
        record_trav = [False for _ in range(len_rows)]

        ##### Result summary counter #####
        res_cnter = 0


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        for rows_idx in range(len_rows):

            ##### Check if the current indexes matched conditions or not #####
            if (not record_trav[rows_idx]):
                record_trav[rows_idx] |= True #Keep updating/overwriting

                for columns_idx in range(len_columns):

                    ##### Check if the current indexed-value matched conditions or not #####
                    if (((isConnected[rows_idx])[columns_idx])):
                        res_cnter += 1 #Keep updating/accumulating

                        self.DFS_Traversal(isConnected, record_trav, rows_idx) #Recursion function call

                        break

                    else:
                        pass

            else:
                pass

        return res_cnter


    def DFS_Traversal(self, isConnected, record_trav, record_idx):
        """
        :type isConnected: List[List[int]]
        :type record_trav: List[bool]
        :type record_idx: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ############
        #Initialize
        ##### Length of sub-columns #####
        len_sub_columns = len(isConnected[record_idx])

        ####################
        #Whole process/flow
        for sub_columns_idx in range(len_sub_columns):

            ##### Check if the current indexed-value matched conditions or not #####
            if (((isConnected[record_idx])[sub_columns_idx])):

                ##### Check if the current indexes matched conditions or not #####
                if ((not record_trav[sub_columns_idx])):
                    record_trav[sub_columns_idx] |= True #Updating/Overwriting

                    self.DFS_Traversal(isConnected, record_trav, sub_columns_idx) #Recursion function call

                else:
                    pass

            else:
                pass
