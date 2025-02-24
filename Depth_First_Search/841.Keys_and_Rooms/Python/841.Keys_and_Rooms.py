class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rooms array #####
        len_rooms = len(rooms)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counter #####
        res_cnter = [0]


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        self.dfsTraversal(rooms, record_dict, 0, res_cnter) #Recursion function call

        return (True if (res_cnter[0] == len_rooms) else False)


    def dfsTraversal(self, rooms, record_dict, record_node, res_cnter):
        """
        :type rooms: List[List[int]]
        :type record_dict: dict
        :type record_node: int
        :type res_cnter: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (record_node in record_dict): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        record_dict[record_node] = True #Update/Record

        res_cnter[0] += 1 #Update/Accumulate

        for next_node in rooms[record_node]:
            self.dfsTraversal(rooms, record_dict, next_node, res_cnter) #Recursion function call
