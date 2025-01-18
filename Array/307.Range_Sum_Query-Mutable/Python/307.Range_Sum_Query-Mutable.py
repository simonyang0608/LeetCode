class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """

        ############
        #Initialize
        ##### Record length #####
        self.record_length = len(nums)

        ##### Nums array #####
        self.nums = nums[:]

        ##### Binary indexed-tree array #####
        self.bit_arry = [0 for _ in range((self.record_length + 1))]

        for nums_idx in range(self.record_length):
            self.build_tree(nums_idx, self.nums[nums_idx]) #Keep updating/recording
        

    def update(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """

        ############
        #Initialize
        ##### Updated index #####
        upd_idx = (index + 1)

        ##### Difference value #####
        diff_val = (val - (self.nums)[index])


        ####################
        #Whole prcoess/flow
        (self.nums)[index] = val #Update/Overwrite

        while (upd_idx <= self.record_length):
            (self.bit_arry)[upd_idx] += diff_val #Keep updating/recording

            upd_idx += (self.lsb)(upd_idx) #Keep updating/traversing
        

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        if (not left): #Issur/Boundary-case handling
            return (self.prefix_sum)(right)

        return ((self.prefix_sum)(right) - (self.prefix_sum((left - 1))))


    def prefix_sum(self, index):
        """
        :type index: int
        :rtype: int
        """
        ############
        #Initialize
        ##### Updated index #####
        upd_idx = (index + 1)

        ##### Result summary value #####
        res_sum_val = 0


        ####################
        #Whole prcoess/flow
        while (upd_idx > 0):
            res_sum_val += (self.bit_arry)[upd_idx] #Keep updating/accumulating

            upd_idx -= (self.lsb)(upd_idx) #Keep updating/traversing

        return res_sum_val


    def build_tree(self, record_idx, record_val):
        """
        :type record_idx: int
        :type record_val: int
        :rtype: None
        """
        ############
        #Initialize
        ##### Updated index #####
        upd_idx = (record_idx + 1)

        while (upd_idx <= self.record_length):
            (self.bit_arry)[upd_idx] += record_val #Keep updating/recording

            upd_idx += (self.lsb)(upd_idx) #Keep updating/traversing


    def lsb(self, record_idx):
        """
        :type record_idx: int
        :rtype: int
        """
        return (record_idx & ((~record_idx + 1)))

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
