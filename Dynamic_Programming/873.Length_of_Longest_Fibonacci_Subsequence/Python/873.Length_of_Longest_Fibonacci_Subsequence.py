class Solution(object):
    def lenLongestFibSubseq(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        len_arr = len(arr)

        record_dict = {arr[0]: 0, arr[1]: 1}

        record_dp = [[2 for _ in range(len_arr)] for _ in range(len_arr)]

        res_max_cnter = 0

        for arr_idx in range(2, len_arr):
            record_dict[arr[arr_idx]] = arr_idx

            for sub_arr_idx in range(arr_idx):
                record_diff_val = (arr[arr_idx] - arr[sub_arr_idx])

                if (record_diff_val in record_dict):
                    if (arr[sub_arr_idx] > record_diff_val):
                        (record_dp[arr_idx])[sub_arr_idx] = ((record_dp[sub_arr_idx])[record_dict[record_diff_val]] + 1)

                        res_max_cnter = max(res_max_cnter, (record_dp[arr_idx])[sub_arr_idx])
                    else:
                        pass
                else:
                    pass

        return (res_max_cnter if (res_max_cnter) else 0)
