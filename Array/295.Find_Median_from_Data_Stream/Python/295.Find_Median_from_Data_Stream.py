class MedianFinder(object):

    def __init__(self):
        """
        :type: None
        :rtype: None
        """
        ############
        #Initialize
        ##### Record heap/priority-queues (i.e. minimun, maximun) #####
        self.record_pq_max, self.record_pq_min = [], []

        ##### Whole process/flow #####
        heapify(self.record_pq_max) #Update/Heapify
        heapify(self.record_pq_min) #Update/Heapify


    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        ####################
        #Whole process/flow
        heappush(self.record_pq_max, ((-1) * num)) #Update/Record
        heappush(self.record_pq_min, ((-1) * heappop(self.record_pq_max))) #Update/Record

        ##### Check if the current size is smaller or not #####
        if (len(self.record_pq_max) < len(self.record_pq_min)):
            heappush(self.record_pq_max, ((-1) * heappop(self.record_pq_min))) #Update/Record 
        else:
            pass


    def findMedian(self):
        """
        :rtype: float
        """
        return ((((-1) * (self.record_pq_max)[0]) / 1.) if (len(self.record_pq_max) > len(self.record_pq_min)) 
                else ((((-1) * (self.record_pq_max)[0]) + self.record_pq_min[0]) / 2.))



# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
