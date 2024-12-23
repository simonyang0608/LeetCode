class Solution(object):
    def maxSubarraySumCircular(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        len_nums = len(nums)

        max_nums = max(nums)

        if (max_nums <= 0):
            return max_nums

        record_min_sum, record_max_sum = 0, 0

        res_min_val, res_max_val = ((9 * (10 ** 8)) + 1), (((-9) * (10 ** 8)) - 1)

        res_total_sum = 0

        for nums_idx in range(len_nums):
            record_max_sum += nums[nums_idx]

            if (record_max_sum < 0):
                record_max_sum &= 0
            else:
                pass

            res_max_val = max(res_max_val, record_max_sum)

            record_min_sum += nums[nums_idx]

            if (record_min_sum > 0):
                record_min_sum &= 0
            else:
                pass

            res_min_val = min(res_min_val, record_min_sum)

            res_total_sum += nums[nums_idx]

        return ((res_total_sum - res_min_val) if ((res_total_sum - res_min_val) > res_max_val) else res_max_val)
