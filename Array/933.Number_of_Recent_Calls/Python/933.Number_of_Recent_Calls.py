class RecentCounter(object):
    def __init__(self):
        """
        :type: None, void
        :rtype: None, void
        """
        ############
        #Initialize
        ##### Record queue #####
        self.record_queue = []

        ##### Record times #####
        self.record_times = ((-1) * 3000)

        ##### Previous times #####
        self.prev_times = 0


    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        ####################
        #Whole process/flow
        self.record_times += (t - self.prev_times) #Update/Accumulate

        while (self.record_queue and ((self.record_queue)[0] < self.record_times)):
            (self.record_queue).pop(0) #Keep updating/popped

        (self.record_queue).append(t) #Update/Record

        self.prev_times = t #Update/Overwrite

        return len(self.record_queue)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
