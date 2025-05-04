class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of stones array #####
        len_stones = len(stones)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [0 for _ in range(len_stones)]

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record index #####
        record_idx = 0


        ###########################################################################
        #Dynamic-programming based loop traversal with recorded dictionary/hashmap
        record_dict[0] = {0: True} #Update/Record

        for stones_idx in range(1, len_stones):
            while ((record_dp[record_idx] + 1) < (stones[stones_idx] - stones[record_idx])):
                record_idx += 1 #Keep updating/traversing

            for sub_idx in range(record_idx, stones_idx):
                record_diff = (stones[stones_idx] - stones[sub_idx]) #Record difference

                ##### Check if the index existed or not #####
                if (sub_idx in record_dict):

                    ##### Check if the current difference existed or not #####
                    if (((record_diff - 1) in record_dict[sub_idx]) or (record_diff in record_dict[sub_idx]) or ((record_diff + 1) in record_dict[sub_idx])):

                        ##### Check if the current index existed or not #####
                        if (stones_idx not in record_dict):
                            record_dict[stones_idx] = {record_diff: True} #Keep updating/recording
                        else:
                            ##### Check if the current difference existed or not #####
                            if (record_diff not in record_dict[stones_idx]):
                                (record_dict[stones_idx])[record_diff] = True #Keep updating/recording
                            else:
                                pass

                        record_dp[stones_idx] = max(record_dp[stones_idx], record_diff) #Keep updating/overwriting
                    else:
                        pass
                else:
                    pass

        return (True if (record_dp[(-1)]) else False)
