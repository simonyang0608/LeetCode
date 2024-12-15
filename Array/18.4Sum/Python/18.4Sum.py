class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        #======================================#
        # Four-pointers based traversal method #
        #======================================#

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


        ####################################
        #Four-pointers based loop traversal
        while (record_trav_ptr < (len_nums - 3)):
            record_left_ptr = (record_trav_ptr + 1) #Record left-pointer

            while (record_left_ptr < (len_nums - 2)):
                record_mid_ptr = (record_left_ptr + 1) #Record middle-pointer
                record_right_ptr = (len_nums - 1) #Record right-pointer

                record_target = (target - (nums[record_trav_ptr] + nums[record_left_ptr])) #Record target

                while (record_mid_ptr < record_right_ptr):

                    ##### Check if the current summary value matched conditions or not #####
                    if ((nums[record_mid_ptr] + nums[record_right_ptr]) < record_target):
                        while (((record_mid_ptr + 1) < record_right_ptr) and (nums[record_mid_ptr] == nums[(record_mid_ptr + 1)])):
                            record_mid_ptr += 1 #Keep updating/traversing

                        record_mid_ptr += 1 #Keep updating/traversing

                    elif ((nums[record_mid_ptr] + nums[record_right_ptr]) > record_target):
                        while (((record_right_ptr - 1) > record_mid_ptr) and (nums[record_right_ptr] == nums[(record_right_ptr - 1)])):
                            record_right_ptr -= 1 #Keep updating/traversing

                        record_right_ptr -= 1 #Keep updating/traversing

                    else:
                        res_arry.append([nums[record_trav_ptr], nums[record_left_ptr], nums[record_mid_ptr], nums[record_right_ptr]]) #Keep updating/recording

                        while (((record_mid_ptr + 1) < record_right_ptr) and (nums[record_mid_ptr] == nums[(record_mid_ptr + 1)])):
                            record_mid_ptr += 1 #Keep updating/traversing

                        while (((record_right_ptr - 1) > record_mid_ptr) and (nums[record_right_ptr] == nums[(record_right_ptr - 1)])):
                            record_right_ptr -= 1 #Keep updating/traversing

                        record_mid_ptr += 1 #Keep updating/traversing
                        record_right_ptr -= 1 #Keep updating/traversing

                while (((record_left_ptr + 1) < len_nums) and ((nums[record_left_ptr] == nums[(record_left_ptr + 1)]))):
                    record_left_ptr += 1 #Keep updating/traversing

                record_left_ptr += 1 #Keep updating/traversing

            while (((record_trav_ptr + 1) < len_nums) and ((nums[record_trav_ptr] == nums[(record_trav_ptr + 1)]))):
                record_trav_ptr += 1 #Keep updating/traversing

            record_trav_ptr += 1 #Keep updating/traversing

        return res_arry
