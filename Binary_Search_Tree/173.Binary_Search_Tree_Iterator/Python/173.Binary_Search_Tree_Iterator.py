# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: None, void
        """
        ############
        #Initialize
        ##### Record array #####
        self.record_arry = []

        ##### Inorder traversal function call #####
        self.inorderTraversal(root)

        ##### Total length #####
        self.total_length = len(self.record_arry)

        ##### Record traversal pointer #####
        self.record_trav_ptr = 0
        

    def next(self):
        """
        :type: None, void
        :rtype: int
        """
        if (self.record_trav_ptr >= self.total_length): #Issue/Boundary-cae handling
            return (-1)

        ####################
        #Whole process/flow
        res_val = (self.record_arry)[self.record_trav_ptr] #Result value

        self.record_trav_ptr += 1 #Update/Traverse

        return res_val
        

    def hasNext(self):
        """
        :type: None, void
        :rtype: bool
        """
        if (self.record_trav_ptr >= self.total_length): #Issue/Boundary-cae handling
            return False

        return True

    
    def inorderTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: None, void
        """
        ############
        #Initialize
        ##### Record stack #####
        record_stack = []

        ####################
        #Whole process/flow
        while (root or record_stack):
            while (root):
                record_stack.append(root) #Keep updating/recording

                root = root.left #Keep updating/overwriting

            left_most_node = record_stack.pop() #Keep updating/overwriting

            (self.record_arry).append(left_most_node.val) #Keep updating/recording

            root = left_most_node.right #Keep updating/overwriting
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
