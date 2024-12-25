class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Sorted operations #####
        nums.sort(reverse = True)

        ##### Record ones summary counter #####
        record_ones_cnter = nums.count(1)

        ##### Result maximun summary counter #####
        res_max_cnter = 1


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value is 1 or not #####
            if (nums[nums_idx] != 1):
                record_pow_val = (nums[nums_idx] ** 2) #Record power value

                ##### Check if the current power value existed or not #####
                if (record_pow_val not in record_dict):
                    record_dict[nums[nums_idx]] = 1 #Keep updating/recording
                else:
                    ##### Check if the current indexed-value existed or not #####
                    if (nums[nums_idx] in record_dict):
                        record_dict[nums[nums_idx]] = (2 + record_dict[record_pow_val]) #Keep updating/recording

                        res_max_cnter = max(res_max_cnter, record_dict[nums[nums_idx]]) #Keep updating/overwriting
                    else:
                        record_dict[nums[nums_idx]] = 1 #Keep updating/recording
            else:
                pass

        return max(res_max_cnter, (record_ones_cnter if ((record_ones_cnter % 2)) else (record_ones_cnter - 1)))
