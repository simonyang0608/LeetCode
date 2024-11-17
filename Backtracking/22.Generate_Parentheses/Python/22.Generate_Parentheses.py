class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        #===================================#
        # Back-track based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = []

        #################################
        #Back-track based loop traversal
        self.backtrackTraversal(n, 1, 0, "(", res_arry) #Recursion function call

        return res_arry


    def backtrackTraversal(self, n, left_sider, right_sider, res_str, res_arry):
        """
        :type n: int
        :type left_sider: int
        :type right_sider: int
        :type res_str: str
        :type res_arry: List[str]
        :rtype: None, void
        """
        #=====================================#
        # Back-track based traversal function #
        #=====================================#
        if ((left_sider == n) and (right_sider == n)): #Issue/Boundary-case handling
            res_arry.append(res_str) #Update/Record

            return

        ####################
        #Whole process/flow
        ##### Check if the current left/right-sider matched conditions or not #####
        if (left_sider < n):
            self.backtrackTraversal(n, (left_sider + 1), right_sider, (res_str + "("), res_arry) #Recursion function call (i.e. left-sider)

        if (right_sider < left_sider):
            self.backtrackTraversal(n, left_sider, (right_sider + 1), (res_str + ")"), res_arry) #Recursion function call (i.e. right-sider)
