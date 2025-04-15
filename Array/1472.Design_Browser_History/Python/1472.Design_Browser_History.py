class BrowserHistory(object):
    def __init__(self, homepage):
        """
        :type homepage: str
        """

        ############
        #Initialize
        ##### Record array #####
        self.record_arry = [homepage]

        ##### Record traversal pointer #####
        self.record_trav_ptr = 0


    def visit(self, url):
        """
        :type url: str
        :rtype: None
        """

        ############
        #Initialize
        ##### Record length #####
        record_length = (len(self.record_arry) - 1)

        ####################
        #Whole process/flow
        while (record_length > self.record_trav_ptr):
            (self.record_arry).pop() #Keep updating/popped

            record_length -= 1 #Keep updating/reducing

        (self.record_arry).append(url) #Update/Record

        self.record_trav_ptr += 1 #Update/Traverse


    def back(self, steps):
        """
        :type steps: int
        :rtype: str
        """

        ####################
        #Whole process/flow
        self.record_trav_ptr = max(0, (self.record_trav_ptr - steps)) #Update/Overwrite

        return (self.record_arry)[self.record_trav_ptr]


    def forward(self, steps):
        """
        :type steps: int
        :rtype: str
        """

        ####################
        #Whole process/flow
        self.record_trav_ptr = min((len(self.record_arry) - 1), (self.record_trav_ptr + steps)) #Update/Overwrite

        return (self.record_arry)[self.record_trav_ptr]
        


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
