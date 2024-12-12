class Solution {
public:
    bool isArraySpecial(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - bool (result flag)             //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        (len_nums--);


        /*One-pass update based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if te current indexed-value matched conditions or not /////
            if ((nums[nums_idx] % 2))
            {
                ///// Check if te next indexed-value matched conditions or not /////
                if ((! (nums[(nums_idx + 1)] % 2))) { ; }
                else { return false; }
            }

            else
            {
                ///// Check if te next indexed-value matched conditions or not /////
                if ((nums[(nums_idx + 1)] % 2)) { ; }
                else { return false; }
            }

        } //Whole

        return true;
    }
};
