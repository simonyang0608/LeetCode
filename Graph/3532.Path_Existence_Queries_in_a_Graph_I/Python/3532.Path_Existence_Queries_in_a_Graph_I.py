class Solution(object):
    def pathExistenceQueries(self, n, nums, maxDiff, queries):
        """
        :type n: int
        :type nums: List[int]
        :type maxDiff: int
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        #=====================================#
        # Disjoint-set based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. nums, queries) #####
        len_nums, len_queries = len(nums), len(queries)

        ##### Record summary counter #####
        record_cnter = 0

        ##### Record array #####
        record_arry = [0 for _ in range(len_nums)]

        ##### Result array #####
        res_arry = [False for _ in range(len_queries)]


        ########################################################
        #Disjoint-set based loop traversal with recorded arrays
        ##### Step 1: Record indexed-values informations with array #####
        for nums_idx in range(1, len_nums):

            ##### Check if the current difference matched conditions or not #####
            if ((nums[nums_idx] - nums[(nums_idx - 1)]) > maxDiff):
                record_cnter += 1 #Keep updating/accumulating
            else:
                pass

            record_arry[nums_idx] = record_cnter #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded array #####
        for queries_idx in range(len_queries):

            ##### Check if the current summary counter matched conditions or not #####
            if (record_arry[(queries[queries_idx])[0]] == record_arry[(queries[queries_idx])[1]]):
                res_arry[queries_idx] = True #Keep updating/overwriting
            else:
                pass

        return res_arry
