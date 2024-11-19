class ListNode(object):

    def __init__(self, val):
        """
        :type val: int
        :rtype: None, void
        """
        ########################
        #Constructor Initialize
        ##### Value #####
        self.val = val

        ##### Next list-node #####
        self.next = None


class MyLinkedList(object):

    def __init__(self):
        """
        :type: None, void
        :rtype: None, void
        """
        ########################
        #Constructor Initialize
        ##### Indexed-length #####
        self.length_idx = 0

        ##### List-node #####
        self.node = None


    def get(self, index):
        """
        :type index: int
        :rtype: int
        """
        if (index >= self.length_idx): #Issue/Boundary-case handling
            return (-1)

        elif (index < 0): #Issue/Boundary-case handling
            return (-1)


        ############
        #Initialize
        ##### Result list-node #####
        res_node = self.node

        ####################
        #Whole process/flow
        for index_idx in range(index):
            res_node = res_node.next #Keep updating/overwriting

        return res_node.val


    def addAtHead(self, val):
        """
        :type val: int
        :rtype: None
        """
        ############
        #Initialize
        ##### Result list-node #####
        res_node = ListNode(val)

        ####################
        #Whole process/flow
        res_node.next = self.node #Update/Overwrite

        self.node = res_node #Update/Overwrite

        self.length_idx += 1 #Update/Accumulate
        

    def addAtTail(self, val):
        """
        :type val: int
        :rtype: None
        """
        if (not self.node): #Issue/Boundary-vase handling
            self.addAtHead(val) #Add at head

        else:
            ############
            #Initialize
            ##### Result list-node #####
            res_node = (self.node)

            ####################
            #Whole process/flow
            while (res_node and (res_node.next)):
                res_node = res_node.next #Keep updating/overwriting

            res_node.next = ListNode(val) #Update/Overwrite

            self.length_idx += 1 #Update/Accumulate
        

    def addAtIndex(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        if (index > self.length_idx): #Issue/Boundary-case handling
            return

        elif (index == 0): #Issue/Boundary-case handling
            self.addAtHead(val) #Add at head

            return

        elif (index == self.length_idx): #Issue/Boundary-case handling
            self.addAtTail(val) #Add at tail

            return


        ############
        #Initialize
        ##### Result list-node #####
        res_node = self.node

        ####################
        #Whole process/flow
        for index_idx in range(1, index):
            res_node = res_node.next #Keep updating/overwriting

        record_node = res_node.next #Record list-node
        res_node.next = ListNode(val) #Update/Overwrite

        (res_node.next).next = record_node #Update/Overwrite

        self.length_idx += 1 #Update/Accumulate
        

    def deleteAtIndex(self, index):
        """
        :type index: int
        :rtype: None
        """
        if (index >= self.length_idx): #Issue/Boundary-case handling
            return

        elif (index < 0): #Issue/Boundary-case handling
            return

        elif (not index): #Issue/Boundary-case handling
            self.node = (self.node.next) #Update/Overwrite

            self.length_idx -= 1 #Update/Reduce

            return


        ############
        #Initialize
        ##### Result list-node #####
        res_node = self.node

        ####################
        #Whole process/flow
        if (not index):
            res_node = res_node.next #Update/Overwrite

            self.node = res_node #Update/Overwrite

        else:
            index -= 1 #Update/Reduce

            for index_idx in range(index):
                res_node = (res_node.next) #Keep updating/overwriting

            res_node.next = (res_node.next).next #Update/Overwrite

        self.length_idx -= 1 #Update/Reduce


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
