class Solution(object):
    def continuousSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #==============================#
        # Deque-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record deques (i.e. minimun, maximun) #####
        record_dq_min, record_dq_max = [], []

        ##### Record two pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result summary counter #####
        res_cnter = 0


        ############################
        #Deque-based loop traversal
        while (record_right_ptr < len_nums):
            while (record_dq_min and (nums[record_dq_min[(-1)]] >= nums[record_right_ptr])):
                record_dq_min.pop() #Keep updating/popped
            
            while (record_dq_max and (nums[record_dq_max[(-1)]] <= nums[record_right_ptr])):
                record_dq_max.pop() #Keep updating/popped

            record_dq_min.append(record_right_ptr) #Keep updating/recording
            record_dq_max.append(record_right_ptr) #Keep updating/recording

            while ((nums[record_dq_max[0]] - nums[record_dq_min[0]]) > 2):
                record_left_ptr += 1 #Keep updating/traversing

                ##### Check if the current index exceed boundary or not #####
                if (record_dq_min[0] < record_left_ptr):
                    record_dq_min.pop(0) #Keep updating/popped
                else:
                    pass

                ##### Check if the current index exceed boundary or not #####
                if (record_dq_max[0] < record_left_ptr):
                    record_dq_max.pop(0) #Keep updating/popped
                else:
                    pass

            res_cnter += (record_right_ptr - record_left_ptr + 1) #Keep updating/accumulating

            record_right_ptr += 1 #Keep updating/traversing

        return res_cnter
