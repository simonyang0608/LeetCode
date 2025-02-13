class Solution(object):
    def minimumIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of nums vector /////
        len_nums = len(nums)

        ##### Record traversal pointer #####
        record_trav_ptr = (len_nums - 1)

        ##### Record dictionary/hashmap (i.e. left, right) #####
        record_left_dict, record_right_dict = {}, {}


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Looped-traversal for the suffix-prefix index #####
        while (record_trav_ptr >= 0):

            ##### Check if the current indexed-value existed or not #####
            if (nums[record_trav_ptr] not in record_right_dict):
                record_right_dict[nums[record_trav_ptr]] = 1 #Keep updating/recording
            else:
                record_right_dict[nums[record_trav_ptr]] += 1 #Keep updating/recording

            record_trav_ptr -= 1 #Keep updating/traversing

        ##### Step 2: Looped-traversal for the prefix-suffix index #####
        record_trav_ptr += 1 #Update/Traverse

        while (record_trav_ptr < len_nums):
            record_num = nums[record_trav_ptr] #Record num

            split_size = (record_trav_ptr + 1) #Split-size

            ##### Check if the current indexed-value existed or not #####
            if (record_num not in record_left_dict):
                record_left_dict[record_num] = 1 #Keep updating/recording
            else:
                record_left_dict[record_num] += 1 #Keep updating/recording

            record_right_dict[record_num] -= 1 #Keep updating/recording

            ##### Check if the current indexed-value is majority or not #####
            if ((record_left_dict[record_num] > (split_size // 2)) and (record_right_dict[record_num] > ((len_nums - split_size) // 2))):
                return record_trav_ptr

            record_trav_ptr += 1 #Keep updating/traversing

        return (-1)
