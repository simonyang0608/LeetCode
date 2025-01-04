class Solution {
public:
    int rob(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Retuurn type:                      //
        //   - int (result maximun value)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        if (len_nums == 1) { return nums[0]; } //Issue, Boundary-case handling

        ///// Record dynamic-programming vectors (i.e. left, right) /////
        vector<int> record_dp_left(len_nums, 0), record_dp_right(len_nums, 0);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        record_dp_left[1] = nums[0]; record_dp_right[1] = nums[1]; //Update, Overwrite

        for (int nums_idx = 2; (nums_idx < len_nums); (nums_idx++)) //Left-half
        {
            record_dp_left[nums_idx] = record_dp_left[(nums_idx - 1)]; //Keep updatiing, transferring

            record_dp_left[nums_idx] = max(record_dp_left[nums_idx], (record_dp_left[(nums_idx - 2)] + nums[(nums_idx - 1)])); //Keep updatiing, overwriiting

        } //Left-half

        for (int nums_idx = 2; (nums_idx < len_nums); (nums_idx++)) //Right-half
        {
            record_dp_right[nums_idx] = record_dp_right[(nums_idx - 1)]; //Keep updatiing, transferring

            record_dp_right[nums_idx] = max(record_dp_right[nums_idx], (record_dp_right[(nums_idx - 2)] + nums[nums_idx])); //Keep updatiing, overwriiting

        } //Right-half

        return (record_dp_left[(len_nums - 1)] > record_dp_right[(len_nums - 1)]) ? record_dp_left[(len_nums - 1)] : record_dp_right[(len_nums - 1)];
    }
};
