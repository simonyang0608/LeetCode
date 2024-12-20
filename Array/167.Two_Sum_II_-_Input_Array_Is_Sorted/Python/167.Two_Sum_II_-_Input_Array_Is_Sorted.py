class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of numbers array #####
        len_numbers = len(numbers)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_numbers - 1)


        ###################################
        #Two-pointers based loop traversal
        while (record_left_ptr < record_right_ptr):

            ##### Check if the current indexed-value matched conditions or not #####
            if ((numbers[record_left_ptr] + numbers[record_right_ptr]) < target):
                record_left_ptr += 1 #Keep updating/traversing

            elif ((numbers[record_left_ptr] + numbers[record_right_ptr]) > target):
                record_right_ptr -= 1 #Keep updating/traversing
            else:
                return [(record_left_ptr + 1), (record_right_ptr + 1)]

        return [(-1), (-1)]
