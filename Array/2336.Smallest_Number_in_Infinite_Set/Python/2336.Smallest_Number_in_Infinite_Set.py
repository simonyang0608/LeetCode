class SmallestInfiniteSet(object):
    def __init__(self):
        """
        :type: None, void
        :rtype: None, void
        """
        ############
        #Initialize
        ##### Record heap/priority-queue #####
        self.record_pq = []

        ##### Record dictionary/hashmap #####
        self.record_dict = {}


        ####################
        #Whole process/flow
        for num_idx in range(1, 1001):
            (self.record_pq).append(num_idx) #Keep updating/recording

            (self.record_dict)[num_idx] = True #Keep updating/recording

        heapify(self.record_pq) #Update/Heapify


    def popSmallest(self):
        """
        :type : None, void
        :rtype: int
        """
        ####################
        #Whole process/flow
        res_val = (self.record_pq)[0] #Result value

        heappop(self.record_pq) #Update/Popped

        del (self.record_dict)[res_val] #Update/Delete

        return res_val
        

    def addBack(self, num):
        """
        :type num: int
        :rtype: None
        """
        ####################
        #Whole process/flow
        ##### Check if the current num existed or not #####
        if (num not in self.record_dict):
            heappush(self.record_pq, num) #Update/Record

            (self.record_dict)[num] = True #Update/Record
        else:
            pass


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
