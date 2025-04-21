class Solution(object):
    def maxProfit(self, inventory, orders):
        """
        :type inventory: List[int]
        :type orders: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of inventory array #####
        len_inventory = len(inventory)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record module #####
        record_module = ((10 ** 9) + 7)

        ##### Result maximun summary value #####
        res_max_sum = 0


        ####################################
        #Binary-search based loop traversal
        ##### Step 1: Looped-traversal for searching for the critical point/index #####
        inventory.sort(reverse = True) #Sorted operations

        record_right_ptr = inventory[0] #Update/Overwrite

        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            record_flag = self.isValid(len_inventory, inventory, record_mid_ptr, orders) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (record_flag):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        ##### Step 2: Looped-traversal for the remainings #####
        for inventory_idx in range(len_inventory):

            ##### Check if the current indexed-value exceed boundary or not #####
            if (inventory[inventory_idx] <= record_right_ptr):
                break

            orders -= (inventory[inventory_idx] - record_right_ptr) #Keep updating/reducing

            res_max_sum += (((inventory[inventory_idx] * (inventory[inventory_idx] + 1)) // 2) - 
                             ((record_right_ptr * (record_right_ptr + 1)) // 2)) #Keep updating/accumulating

            res_max_sum %= record_module #Keep updating/moduling

        res_max_sum += (orders * record_right_ptr) #Update/Accumulate

        res_max_sum %= record_module #Update/Module

        return res_max_sum

        
    def isValid(self, len_inventory, inventory, record_val, orders):
        """
        :type len_inventory: int
        :type inventory: List[int]
        :type record_val: int
        :type orders: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Result summary counter #####
        res_cnter = 0

        ####################
        #Whole process/flow
        for inventory_idx in range(len_inventory):

            ##### Check if the current indexed-value exceed boundary or not #####
            if (inventory[inventory_idx] < record_val):
                break

            res_cnter += (inventory[inventory_idx] - record_val + 1) #Keep updating/accumulating

            ##### Check if the current summary counter matched conditions or not #####
            if (res_cnter > orders):
                return False

        return True
