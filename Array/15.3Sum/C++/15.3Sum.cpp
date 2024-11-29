class Solution {
public:
    vector<vector<int>> threeSum(vector<int> & nums) 
    {
        //=========================================//
        // Input type:                             //
        //   - vector<int> ref. (nums vector)      //
        // Return type:                            //
        //   - vector<vector<int>> (result vector) //
        //=========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, middle, right) /////
        int record_left_ptr = 0, record_mid_ptr, record_right_ptr;

        ///// Sorted operations /////
        sort(nums.begin(), nums.end());

        ///// Record difference value /////
        int record_diff;

        ///// Result vector /////
        vector<vector<int>> res_vect; 


        /*Three-pointers based loop traversal*/
        while (record_left_ptr < (len_nums - 2)) //Whole
        {
            record_mid_ptr = (record_left_ptr + 1); //Record middle pointer
            record_right_ptr = (len_nums - 1); //Record right pointer

            record_diff = (nums[record_left_ptr] * (-1)); //Record difference value

            while (record_mid_ptr < record_right_ptr) //Part
            {
                ///// Check if the current summary matched conditions or not /////
                if ((nums[record_mid_ptr] + nums[record_right_ptr]) < record_diff)
                {
                    while (((record_mid_ptr + 1) < len_nums) && (nums[record_mid_ptr] == nums[(record_mid_ptr + 1)])) //Part
                    {
                        (record_mid_ptr++); //Keep updating, traversing

                    } //Part

                    (record_mid_ptr++); //Keep updating, traversing
                }

                else if ((nums[record_mid_ptr] + nums[record_right_ptr]) > record_diff)
                {
                    while (((record_right_ptr - 1) >= 0) && (nums[record_right_ptr] == nums[(record_right_ptr - 1)])) //Part
                    {
                        (record_right_ptr--); //Keep updating, traversing

                    } //Part

                    (record_right_ptr--); //Keep updating, traversing
                }

                else
                {
                    res_vect.push_back({nums[record_left_ptr], nums[record_mid_ptr], nums[record_right_ptr]}); //Keep updating, recording

                    while (((record_mid_ptr + 1) < len_nums) && (nums[record_mid_ptr] == nums[(record_mid_ptr + 1)])) //Part
                    {
                        (record_mid_ptr++); //Keep updating, traversing

                    } //Part

                    while (((record_right_ptr - 1) >= 0) && (nums[record_right_ptr] == nums[(record_right_ptr - 1)])) //Part
                    {
                        (record_right_ptr--); //Keep updating, traversing

                    } //Part

                    (record_mid_ptr++); //Keep updating, traversing
                    (record_right_ptr--); //Keep updating, traversing
                }

            } //Part

            while (((record_left_ptr + 1) < len_nums) && (nums[record_left_ptr] == nums[(record_left_ptr + 1)])) //Part
            {
                (record_left_ptr++); //Keep updating, traversing

            } //Part

            (record_left_ptr++); //Keep updating, traversing

        } //Whole

        return res_vect;
    }
};
