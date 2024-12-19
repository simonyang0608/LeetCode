class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        #========================#
        # Constructor initialize #
        #========================#

        ############
        #Initialize
        ##### Length of nums array #####
        self.len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        self.record_dict = {}


        ####################
        #Whole process/flow
        for self.nums_idx in range(self.len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[self.nums_idx] not in self.record_dict):
                (self.record_dict[nums[self.nums_idx]]) = [self.nums_idx] #Keep updating/recording
            else:
                (self.record_dict[nums[self.nums_idx]]).append(self.nums_idx) #Keep updating/recording


    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        return (self.record_dict[target])[randint(0, len(self.record_dict[target]) - 1)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
