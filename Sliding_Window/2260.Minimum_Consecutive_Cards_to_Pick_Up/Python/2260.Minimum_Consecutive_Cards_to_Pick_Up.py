class Solution(object):
    def minimumCardPickup(self, cards):
        """
        :type cards: List[int]
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of cards array #####
        len_cards = len(cards)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record flag #####
        record_flag = False

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result minimun length #####
        res_min_length = float("inf")


        #######################################################################
        #Sliding-window based loop traversal with recorded dictionary, hashmap
        while (record_right_ptr < len_cards):
            curr_val = cards[record_right_ptr] #Current value

            ##### Check if the current indexed-value existed or not #####
            if (curr_val not in record_dict):
                record_dict[curr_val] = 1 #Keep updating/recording
            else:
                record_dict[curr_val] += 1 #Keep updating/recording

            ##### Check if the current summary counter matched conditions or not #####
            if (record_dict[curr_val] >= 2):
                record_flag |= True #Keep updating/overwriting
            else:
                pass

            while (record_flag):
                res_min_length = min(res_min_length, (record_right_ptr - record_left_ptr + 1)) #Keep updating/overwriting

                record_dict[cards[record_left_ptr]] -= 1 #Keep updating/recording

                ##### Check if the current summary counter matched conditions or not #####
                if (record_dict[cards[record_left_ptr]] == 1):
                    record_flag &= False #Keep updating/overwriting
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            record_right_ptr += 1 #Keep updating/traversing

        return ((-1) if (res_min_length == float("inf")) else res_min_length)
