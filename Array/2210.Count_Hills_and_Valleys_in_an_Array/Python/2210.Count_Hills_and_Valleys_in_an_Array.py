class Solution(object):
    def countHillValley(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counter #####
        res_cnter = 0


        ####################################################################
        #Two-pointers based loop traversal with recorded dictionary/hashmap
        for nums_idx in range(1, (len_nums - 1)):
            record_left_ptr, record_right_ptr = (nums_idx - 1), (nums_idx + 1) #Record two-pointers (i.e. left, right)

            while ((record_left_ptr >= 0) and (nums[record_left_ptr] == nums[nums_idx])):
                record_left_ptr -= 1 #Keep updating/traversing
            
            while ((record_right_ptr < len_nums) and (nums[record_right_ptr] == nums[nums_idx])):
                record_right_ptr += 1 #Keep updating/traversing

            ##### Check if the current indexes exceed boundary or not #####
            if ((record_left_ptr < 0) or (record_right_ptr >= len_nums)):
                continue

            ##### Check if the current indexed-values matched conditions or not #####
            if ((nums[record_left_ptr] < nums[nums_idx]) and (nums[record_right_ptr] < nums[nums_idx])):

                ##### Check if the current indexed-values existed or not #####
                if ((record_left_ptr, record_right_ptr) not in record_dict):
                    record_dict[(record_left_ptr, record_right_ptr)] = True #Keep updating/recording

                    res_cnter += 1 #Keep updating/accumulating
                else:
                    pass

            elif ((nums[record_left_ptr] > nums[nums_idx]) and (nums[record_right_ptr] > nums[nums_idx])):

                ##### Check if the current indexed-values existed or not #####
                if ((record_left_ptr, record_right_ptr) not in record_dict):
                    record_dict[(record_left_ptr, record_right_ptr)] = True #Keep updating/recording

                    res_cnter += 1 #Keep updating/accumulating
                else:
                    pass

            else:
                pass

        return res_cnter
