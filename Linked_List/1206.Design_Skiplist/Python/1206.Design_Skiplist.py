class Skiplist(object):
    def __init__(self):
        """
        :type void: None, void
        :rtype: void
        """

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        self.record_dict = {}


    def search(self, target):
        """
        :type target: int
        :rtype: bool
        """

        ####################
        #Whole process/flow
        ##### Check if the current target existed or not #####
        if (target not in self.record_dict):
            return False

        return True


    def add(self, num):
        """
        :type num: int
        :rtype: None
        """

        ####################
        #Whole process/flow
        ##### Check if the current num existed or not #####
        if (num not in self.record_dict):
            (self.record_dict)[num] = 1 #Update/Record
        else:
            (self.record_dict)[num] += 1 #Update/Accumulate
        

    def erase(self, num):
        """
        :type num: int
        :rtype: bool
        """

        ####################
        #Whole process/flow
        ##### Check if the current num existed or not #####
        if (num not in self.record_dict):
            return False

        (self.record_dict)[num] -= 1 #Update/Reduce

        ##### Check if the current num matched conditions or not #####
        if (not (self.record_dict)[num]):
            del (self.record_dict)[num] #Update/Delete
        else:
            pass

        return True



# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)
