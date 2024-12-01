class Solution {
public:
    int maxResult(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th steps)               //
        // Return type:                       //
        //   - int (result maximun score)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp(len_nums, 0);

        record_dp[0] = nums[0];

        ///// Record priority-queue /////
        priority_queue<pair<int, int>> record_pq;

        record_pq.push(make_pair(record_dp[0], 0));


        /*Dynamic-programming based loop traversal*/
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            while ((! record_pq.empty()) && ((nums_idx - (record_pq.top()).second) > k)) //Part
            {
                record_pq.pop(); //Keep updating, popped

            } //Part

            record_dp[nums_idx] += (((record_pq.top()).first) + nums[nums_idx]); //Keep updating, overwriting

            record_pq.push(make_pair(record_dp[nums_idx], nums_idx)); //Keep updating, recording

        } //Whole

        return record_dp[(len_nums - 1)];

    }
};
