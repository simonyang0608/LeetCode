class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        #=======================================#
        # Three-pointers based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Sorted operations #####
        nums.sort()

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result array #####
        res_arry = []


        #####################################
        #Three-pointers based loop traversal
        while (record_trav_ptr < (len_nums - 2)):
            record_diff = (nums[record_trav_ptr] * (-1)) #Record difference

            record_left_ptr, record_right_ptr = (record_trav_ptr + 1), (len_nums - 1) #Record pointers (i.e. left, right) #####

            while (record_left_ptr < record_right_ptr):

                ##### Check if the current summary matched conditions or not #####
                if ((nums[record_left_ptr] + nums[record_right_ptr]) < record_diff):
                    while (((record_left_ptr + 1) < record_right_ptr) and (nums[record_left_ptr] == nums[(record_left_ptr + 1)])):
                        record_left_ptr += 1 #Keep updating/traversing

                    record_left_ptr += 1 #Keep updating/traversing

                elif ((nums[record_left_ptr] + nums[record_right_ptr]) > record_diff):
                    while (((record_right_ptr - 1) > record_left_ptr) and (nums[record_right_ptr] == nums[(record_right_ptr - 1)])):
                        record_right_ptr -= 1 #Keep updating/traversing

                    record_right_ptr -= 1 #Keep updating/traversing

                else:
                    res_arry.append([nums[record_trav_ptr], nums[record_left_ptr], nums[record_right_ptr]]) #Keep updating/recording

                    while (((record_left_ptr + 1) < record_right_ptr) and (nums[record_left_ptr] == nums[(record_left_ptr + 1)])):
                        record_left_ptr += 1 #Keep updating/traversing

                    while (((record_right_ptr - 1) > record_left_ptr) and (nums[record_right_ptr] == nums[(record_right_ptr - 1)])):
                        record_right_ptr -= 1 #Keep updating/traversing

                    record_left_ptr += 1 #Keep updating/traversing
                    record_right_ptr -= 1 #Keep updating/traversing

            while (((record_trav_ptr + 1) < len_nums) and (nums[record_trav_ptr] == nums[(record_trav_ptr + 1)])):
                record_trav_ptr += 1 #Keep updating/traversing

            record_trav_ptr += 1 #Keep updating/traversing

        return res_arry
