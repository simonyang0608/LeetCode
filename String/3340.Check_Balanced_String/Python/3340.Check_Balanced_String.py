class Solution(object):
    def isBalanced(self, num):
        """
        :type num: str
        :rtype: bool
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums string #####
        len_num = len(num)

        ##### Record two-pointers (i.e. even, odd) #####
        record_even_ptr, record_odd_ptr = 0, 1

        ##### Result summary values (i.e. even, odd) #####
        res_sum_even, res_sum_odd = 0, 0


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-traversal for the overlapped-part #####
        while ((record_even_ptr < len_num) and (record_odd_ptr < len_num)):
            res_sum_even += int(num[record_even_ptr]) #Keep updating/accumulating
            res_sum_odd += int(num[record_odd_ptr]) #Keep updating/accumulating

            record_even_ptr += 2 #Keep updating/traversing
            record_odd_ptr += 2 #Keep updating/traversing

        ##### Step 2: Looped-traversal for the remainings #####
        while (record_even_ptr < len_num):
            res_sum_even += int(num[record_even_ptr]) #Keep updating/accumulating

            record_even_ptr += 2 #Keep updating/traversing

        while (record_odd_ptr < len_num):
            res_sum_odd += int(num[record_odd_ptr]) #Keep updating/accumulating

            record_odd_ptr += 2 #Keep updating/traversing

        return (res_sum_even == res_sum_odd)
