class Solution(object):
    def destroyTargets(self, nums, space):
        """
        :type nums: List[int]
        :type space: int
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record, Visit dictionary, hashmap #####
        record_dict, visit_dict = {}, {}

        ##### Result value, maximun summary counter #####
        res_val, res_max_cnter = 0, 0


        #####################################################
        #Hashmap-based loop traversal with sorted operations
        ##### Step 1: Record indexed-value informations with dictionary/hashmap #####
        nums.sort() #Sorted operations

        for nums_idx in range(len_nums):
            record_remains = (nums[nums_idx] % space) #Record remainings

            ##### Check if the current remainings existed or not #####
            if (record_remains not in record_dict):
                record_dict[record_remains] = 1 #Keep updating/recording
            else:
                record_dict[record_remains] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for nums_idx in range(len_nums):

            ##### Check if the current remainings visited or not #####
            if ((nums[nums_idx] % space) in visit_dict):
                continue

            record_remains = (nums[nums_idx] % space) #Record remainings

            visit_dict[record_remains] = True #Keep updating/recording

            ##### Check if the current summary counter is larger or not #####
            if (record_dict[record_remains] > res_max_cnter):
                res_max_cnter = record_dict[record_remains] #Keep updating/overwriting

                res_val = nums[nums_idx] #Keep updating/overwriting
            else:
                pass

        return res_val
