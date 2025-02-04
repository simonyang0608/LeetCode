class MinStack(object):
    def __init__(self):
        """
        :rtype: None
        """
        ############
        #Initialize
        ##### Record stack, min-stack #####
        self.record_stack, self.record_min_stack = [], []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        ####################
        #Whole process/flow
        (self.record_stack).append(val) #Update/Record

        ##### Check if the current stack is empty or not #####
        if (not self.record_min_stack):
            (self.record_min_stack).append(val) #Update/Record
        else:
            ##### Check if the current value matched is smaller or not #####
            if (val <= (self.record_min_stack)[(-1)]):
                (self.record_min_stack).append(val) #Update/Record
            else:
                pass


    def pop(self):
        """
        :rtype: None
        """
        ####################
        #Whole process/flow
        record_val = (self.record_stack).pop() #Record value

        ##### Check if the current value matched conditions or not #####
        if (record_val == (self.record_min_stack)[(-1)]):
            (self.record_min_stack).pop() #Update/Popped
        else:
            pass


    def top(self):
        """
        :rtype: int
        """
        return (self.record_stack)[(-1)]    

    def getMin(self):
        """
        :rtype: int
        """
        return (self.record_min_stack)[(-1)]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
