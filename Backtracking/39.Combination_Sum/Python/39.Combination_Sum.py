class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        #============================================#
        # Recursion-based backtrack traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of candidates array #####
        len_candidates = len(candidates)

        ##### Result array #####
        res_arry = []


        ##########################################
        #Recursion-based Backtrack loop traversal
        candidates.sort() #Sorted operations

        self.backtrackTraversal(len_candidates, candidates, target, 0, [], res_arry) #Recursion function call

        return res_arry

        
    def backtrackTraversal(self, len_candidates, candidates, target, record_idx, record_arry, res_arry):
        """
        :type len_candidates: int
        :type candidates: List[int]
        :type target: int
        :type record_idx: int
        :type record_arry: List[int]
        :type res_arry: List[List[int]]
        :rtype: None, void
        """
        #==============================================#
        # Recursion-based backtrack traversal function #
        #==============================================#
        if (record_idx >= len_candidates): #Issue/Boundary-case handling
            return

        if (target < 0): #Issue/Boundary-case handling
            return

        if (not target): #Issue/Boundary-case handling
            res_arry.append(record_arry) #Update/Record

            return


        ####################
        #Whole process/flow
        for sub_idx in range(record_idx, len_candidates):
            self.backtrackTraversal(len_candidates, candidates, (target - candidates[sub_idx]), sub_idx, 
                                    (record_arry + [candidates[sub_idx]]), res_arry) #Recursion function call
