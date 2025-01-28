class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #==============================#
        # Gredy-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        if (len_nums == 1): #Issue/Boundary-case handling
            return 0

        ##### Record boundary, farest index #####
        record_bound, record_farest = 0, 0

        ##### Result minimun steps #####
        res_min_steps = 0


        ############################
        #Gredy-based loop traversal
        for nums_idx in range((len_nums - 1)):
            record_farest = max(record_farest, (nums_idx + nums[nums_idx])) #Record farest

            ##### Check if the current index reaches boundary or not #####
            if (nums_idx == record_bound):
                res_min_steps += 1 #Keep updating/accumulating

                record_bound = record_farest #Keep updating/overwriting
            else:
                pass

        return res_min_steps
