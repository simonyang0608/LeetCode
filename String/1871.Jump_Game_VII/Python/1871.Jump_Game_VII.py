class Solution(object):
    def canReach(self, s, minJump, maxJump):
        """
        :type s: str
        :type minJump: int
        :type maxJump: int
        :rtype: bool
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#
        if (s[-1] == "1"): #Issue/Boundary-case handling
            return False

        if ((len(s) > minJump) and (len(s) <= (maxJump + 1))): #Issue/Boundary-case handling
            return True

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record dynamic-programming (i.e DP) array #####
        record_dp = [1 for _ in range(minJump)]


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for s_idx in range(minJump, len_s):
            res_reach_diff = 0 #Result reached-differences

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[s_idx] == "0"):
                res_reach_diff += record_dp[(s_idx - minJump)] #Keep updating/accumulating

                ##### Check if the current indexes matched conditions or not #####
                if (s_idx > maxJump):
                    res_reach_diff -= record_dp[(s_idx - maxJump - 1)] #Keep updating/reducing
                else:
                    pass

            else:
                pass

            ##### Check if the current differences matched conditions or not #####
            if (res_reach_diff):
                record_dp.append((record_dp[-1] + 1)) #Keep updating/recording
            else:
                record_dp.append(record_dp[-1]) #Keep updating/recording

        return (True if (res_reach_diff) else False)
