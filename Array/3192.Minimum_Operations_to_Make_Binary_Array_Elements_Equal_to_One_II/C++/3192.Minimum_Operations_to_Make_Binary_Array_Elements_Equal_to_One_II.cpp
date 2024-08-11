class Solution {
public:
    int minOperations(vector<int> & nums) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums vector)  //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record indexed-bit /////
        int record_bit = 1;

        ///// Result minimun operations /////
        int res_min_oprs = 0;


        /*Greedy-based loop traversal with recorded indexed-bit*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-bit matched conditions or not /////
            if (nums[nums_idx] != record_bit)
            {
                (res_min_oprs++); //Keep updating, accumulating

                record_bit = nums[nums_idx]; //Keep updating, overwriting
            }

            else { ; }

        } //Whole

        return res_min_oprs;
    }
};
