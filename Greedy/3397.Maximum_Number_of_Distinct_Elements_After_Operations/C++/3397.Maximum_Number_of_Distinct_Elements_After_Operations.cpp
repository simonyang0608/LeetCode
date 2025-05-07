class Solution {
public:
    int maxDistinctElements(vector<int> & nums, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        //   - int (k-th ranges)                    //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record maximun value /////
        int record_max_val = INT_MIN;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Greedy-based loop traversal*/
        sort(nums.begin(), nums.end()); //Sorted operations

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current difference matched conditions or not /////
            if ((nums[nums_idx] + k) <= record_max_val) { continue; }

            (res_max_cnter++); //Keep updating, accumulating

            record_max_val = max((record_max_val + 1), (nums[nums_idx] - k)); //Keep updating, overwriting

        } //Whole

        return res_max_cnter;
    }
};
