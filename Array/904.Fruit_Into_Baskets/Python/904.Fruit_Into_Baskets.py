class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of fruits array #####
        len_fruits = len(fruits)

        if (len_fruits < 3): #Issue/Boundary-case handling
            return len_fruits

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_fruits):

            ##### Check if the current indexed-value existed or not #####
            if (fruits[record_right_ptr] not in record_dict):
                record_dict[fruits[record_right_ptr]] = 1 #Keep updating/recording
            else:
                record_dict[fruits[record_right_ptr]] += 1 #Keep updating/recording

            ##### Check if the current fruits types exceed boundary or not #####
            while (len(record_dict) > 2):
                record_dict[fruits[record_left_ptr]] -= 1 #Keep updating/recording

                ##### Check if the current indexed-value matched conditions or not #####
                if (not record_dict[fruits[record_left_ptr]]):
                    del record_dict[fruits[record_left_ptr]] #Keep updating/delete
                else:
                    pass

                record_left_ptr += 1 #Keep updating/travsersing

            res_max_cnter = max(res_max_cnter, ((record_right_ptr - record_left_ptr) + 1)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/travsersing

        return res_max_cnter
