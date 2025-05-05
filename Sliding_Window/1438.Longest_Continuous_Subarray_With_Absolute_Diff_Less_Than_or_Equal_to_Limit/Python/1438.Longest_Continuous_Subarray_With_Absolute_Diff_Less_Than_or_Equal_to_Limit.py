class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record deques (i.e. minimun, maximun) #####
        record_dq_min, record_dq_max = [], []

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result maximun length #####
        res_max_length = 0


        ##########################################################
        #Sliding-window based loop traversal with recorded deques
        while (record_right_ptr < len_nums):
            while (record_dq_min and (record_dq_min[(-1)] > nums[record_right_ptr])):
                record_dq_min.pop() #Keep updating/popped
            
            record_dq_min.append(nums[record_right_ptr]) #Keep updating/recording

            while (record_dq_max and (record_dq_max[(-1)] < nums[record_right_ptr])):
                record_dq_max.pop() #Keep updating/popped
            
            record_dq_max.append(nums[record_right_ptr]) #Keep updating/recording

            while ((record_dq_max[0] - record_dq_min[0]) > limit):

                ##### Check if the maximun value matched conditions or not #####
                if (record_dq_max[0] == nums[record_left_ptr]):
                    record_dq_max.pop(0) #Keep updating/popped
                else:
                    pass

                ##### Check if the minimun value matched conditions or not #####
                if (record_dq_min[0] == nums[record_left_ptr]):
                    record_dq_min.pop(0) #Keep updating/popped
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            res_max_length = max(res_max_length, (record_right_ptr - record_left_ptr + 1)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

        return res_max_length
