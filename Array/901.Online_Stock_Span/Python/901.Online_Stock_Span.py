class StockSpanner(object):
    def __init__(self):
        """
        :type: None, void
        :rtype: None, void
        """
        ############
        #Initialize
        ##### Record stack #####
        self.record_stack = []


    def next(self, price):
        """
        :type price: int
        :rtype: int
        """
        ############
        #Initialize
        ##### Record span #####
        record_span = 1

        ####################
        #Whole process/flow
        while ((self.record_stack) and ((self.record_stack[(-1)])[0] <= price)):
            record_span += ((self.record_stack).pop())[1] #Keep updating/accumulating

        (self.record_stack).append((price, record_span)) #Keep updating/recording

        return record_span
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
