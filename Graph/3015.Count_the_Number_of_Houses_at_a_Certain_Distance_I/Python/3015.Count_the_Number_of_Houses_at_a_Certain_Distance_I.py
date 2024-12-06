class Solution(object):
    def countOfPairs(self, n, x, y):
        """
        :type n: int
        :type x: int
        :type y: int
        :rtype: List[int]
        """
        #=============================================#
        # Minimun path-summary based traversal method #
        #=============================================#
        
        ############
        #Initialize
        ##### X, Y connections #####
        x -= 1
        y -= 1

        ##### Record houses (i.e. minimun, maximun) #####
        record_min_house, record_max_house = min(x, y), max(x, y)

        ##### Result array #####
        res_arry = [0 for _ in range(n)]


        ###########################################
        #Minimun path-summary based loop traversal
        for n_idx in range((n - 1)):
            for path_idx in range((n_idx + 1), n):
                record_min = min((path_idx - n_idx), ((abs(path_idx - record_max_house) + abs(record_min_house - n_idx)) + 1)) #Keep updating/overwriting

                res_arry[(record_min - 1)] += 2 #Keep updating/recording

        return res_arry
