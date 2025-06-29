class FreqStack(object):
    def __init__(self):
        """
        :itype: None
        :rtype: None
        """
        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        self.record_dict = {}

        ##### Record index #####
        self.record_idx = 0

        ##### Record heap/priority-queue #####
        self.record_pq = []

        heapify(self.record_pq)


    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        ####################
        #Whole process/flow
        ##### Check if the current indexed-value existed or not #####
        if (val not in self.record_dict):
            (self.record_dict)[val] = 1 #Update/Record
        else:
            (self.record_dict)[val] += 1 #Update/Record

        heappush(self.record_pq, [((-1) * (self.record_dict)[val]), ((-1) * self.record_idx), 
                                   val]) #Update/Record

        self.record_idx += 1 #Update/Accumulate
        

    def pop(self):
        """
        :rtype: int
        """
        ####################
        #Whole process/flow
        res_val = ((self.record_pq)[0])[2] #Result value

        heappop(self.record_pq) #Update/Popped

        (self.record_dict)[res_val] -= 1 #Update/Reduce

        return res_val


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
