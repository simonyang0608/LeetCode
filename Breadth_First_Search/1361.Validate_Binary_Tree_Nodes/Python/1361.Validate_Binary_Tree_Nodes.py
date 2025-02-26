class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        """
        :type n: int
        :type leftChild: List[int]
        :type rightChild: List[int]
        :rtype: bool
        """
        #==================================#
        # Queue-based BFS traversal method #
        #==================================#

        ############
        #Initialize
        ##### Length of leftChild array #####
        len_leftChild = len(leftChild)

        ##### Edge counter array #####
        edge_cnter_arry = [0 for _ in range(n)]

        ##### Record queue #####
        record_queue = []

        ##### Root node #####
        root_node = (-1)

        ##### Result summary counter #####
        res_cnter = 0


        ################################
        #Queue-based BFS loop traversal
        ##### Step 1: Looped-traversal for filtering doubled-parent node #####
        for record_idx in range(n):
            left_node, right_node = leftChild[record_idx], rightChild[record_idx] #Left, Right node

            ##### Check if the left-child node is empty or not #####
            if (left_node != (-1)):
                edge_cnter_arry[left_node] += 1 #Keep updating/recording

                ##### Check if the current node has more than 1 parent node or not #####
                if (edge_cnter_arry[left_node] > 1):
                    return False
                else:
                    pass
            else:
                pass

            ##### Check if the right-child node is empty or not #####
            if (right_node != (-1)):
                edge_cnter_arry[right_node] += 1 #Keep updating/recording

                ##### Check if the current node has more than 1 parent node or not #####
                if (edge_cnter_arry[right_node] > 1):
                    return False
                else:
                    pass
            else:
                pass

        ##### Step 2: Looped-traversal for filtering root more than 1 #####
        for n_idx in range(n):

            ##### Check if the current node is root or not #####
            if (edge_cnter_arry[n_idx]):
                continue

            ##### Check if it has more than 1 root or not #####
            if (root_node != (-1)):
                return False

            root_node = n_idx #Keep updating/overwriting

        ##### Step 3: Looped-traversal for the final graph, tree #####
        if (root_node == (-1)): #Issue/Boundary-case handling
            return False

        record_queue.append(root_node) #Update/Record

        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                record_node = record_queue.pop(0) #Record node

                res_cnter += 1 #Keep updating/accumulating

                ##### Check if the next left node is empty or not #####
                if (leftChild[record_node] != (-1)):
                    record_queue.append(leftChild[record_node]) #Keep updating/recording
                else:
                    pass

                ##### Check if the next right node is empty or not #####
                if (rightChild[record_node] != (-1)):
                    record_queue.append(rightChild[record_node]) #Keep updating/recording
                else:
                    pass

        return (True if (res_cnter == n) else False)
