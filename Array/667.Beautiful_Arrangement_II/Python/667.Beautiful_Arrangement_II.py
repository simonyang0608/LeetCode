class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, n

        ##### Record cycled-times #####
        record_times = (k - 1)

        ##### Record char #####
        record_char = 'l'
 
        ##### Result array #####
        res_arry = []


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-traversal for the cycled-times #####
        for times_idx in range(record_times):

            ##### Check if the current char matcehed conditions or not #####
            if (record_char == 'l'):
                res_arry.append(record_left_ptr) #Keep updating/recording

                record_left_ptr += 1 #Keep updating/traversing

                record_char = 'r' #Keep updating/overwriting

            else:
                res_arry.append(record_right_ptr) #Keep updating/recording

                record_right_ptr -= 1 #Keep updating/traversing

                record_char = 'l' #Keep updating/overwriting

        ##### Step 2: Post-process/Final completions #####
        while (record_left_ptr <= record_right_ptr):

            ##### Check if the current char matcehed conditions or not #####
            if (record_char == 'l'):
                res_arry.append(record_left_ptr) #Keep updating/recording

                record_left_ptr += 1 #Keep updating/traversing

            else:
                res_arry.append(record_right_ptr) #Keep updating/recording

                record_right_ptr -= 1 #Keep updating/traversing

        return res_arry
