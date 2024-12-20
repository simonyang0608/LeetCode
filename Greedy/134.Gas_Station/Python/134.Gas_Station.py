class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of gas array #####
        len_gas = len(gas)

        ##### Record fuel #####
        record_fuel = 0

        ##### Record fee #####
        record_fee = 0

        ##### Result index #####
        res_idx = 0


        #############################
        #Greedy-based loop traversal
        for record_idx in range(len_gas):
            record_fuel += (gas[record_idx] - cost[record_idx]) #Keep updating/accumulating

            ##### Check if the current fuel matched conditions or not #####
            if (record_fuel < 0):
                res_idx = (record_idx + 1) #Keep updating/overwriting

                record_fee += record_fuel #Keep updating/accumulating

                record_fuel &= 0 #Keep updating/reset
            else:
                pass

        return (res_idx if ((record_fuel + record_fee) >= 0) else (-1))
