class Solution(object):
    def countCompleteSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array, set #####
        len_nums, len_set = len(nums), (-1)

        ##### Record set #####
        record_set = set(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result summary counter #####
        res_cnter = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        len_set = len(record_set) #Update/Overwrite

        while (record_right_ptr < len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[record_right_ptr] not in record_dict):
                record_dict[nums[record_right_ptr]] = 1 #Keep updating/recording
            else:
                record_dict[nums[record_right_ptr]] += 1 #Keep updating/recording

            while (len(record_dict) >= len_set):
                res_cnter += (len_nums - record_right_ptr) #Keep updating/accumulating

                record_dict[nums[record_left_ptr]] -= 1 #Keep updating/recording

                ##### Check if the current summary counter matched conditions or not #####
                if (not record_dict[nums[record_left_ptr]]):
                    del record_dict[nums[record_left_ptr]] #Keep updating/delete
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            record_right_ptr += 1 #Keep updating/traversing

        return res_cnter
