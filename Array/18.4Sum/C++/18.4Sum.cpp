class Solution {
public:
    vector<vector<int>> fourSum(vector<int> & nums, int target) 
    {
        //=========================================//
        // Input type:                             //
        //   - vector<int> ref. (nums vector)      //
        //   - int (target value)                  //
        // Return type:                            //
        //   - vector<vector<int>> (result vector) //
        //=========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Sorted operations /////
        sort(nums.begin(), nums.end());

        ///// Record pointers (i.e. traversal, left, middle, right) /////
        int record_trav_ptr = 0, record_left_ptr, record_mid_ptr, record_right_ptr;

        ///// Record target, summary value /////
        long long record_target, record_sum;

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Four-pointers based loop traversal*/
        while (record_trav_ptr < (len_nums - 3)) //Traversal-pointer
        {
            record_left_ptr = (record_trav_ptr + 1); //Record left-pointer

            while (record_left_ptr < (len_nums - 2)) //Left-pointer
            {
                record_mid_ptr = (record_left_ptr + 1); //Record middle pointer
                record_right_ptr = (len_nums - 1); //Record right pointer

                record_sum = (nums[record_trav_ptr] + nums[record_left_ptr]); //Record summary value

                record_target = (target - record_sum); //Record target value

                while (record_mid_ptr < record_right_ptr) //Closed-intervals
                {
                    ///// Check if the current summary value matched conditions or not /////
                    if ((nums[record_mid_ptr] + nums[record_right_ptr]) > record_target)
                    {
                        while (((record_right_ptr - 1) > record_mid_ptr) && (nums[record_right_ptr] == nums[(record_right_ptr - 1)])) //Part
                        { 
                            (record_right_ptr--); //Keep updating, traversing

                        } //Part

                        (record_right_ptr--); //Keep updating, traversing
                    }

                    else if ((nums[record_mid_ptr] + nums[record_right_ptr]) < record_target)
                    {
                        while (((record_mid_ptr + 1) < record_right_ptr) && (nums[record_mid_ptr] == nums[(record_mid_ptr + 1)])) //Part
                        {
                            (record_mid_ptr++); //Keep updating, traversing

                        } //Part

                        (record_mid_ptr++); //Keep updating, traversing
                    }

                    else
                    {
                        res_vect.push_back({nums[record_trav_ptr], nums[record_left_ptr], nums[record_mid_ptr], nums[record_right_ptr]}); //Keep updating, recording

                        while (((record_right_ptr - 1) > record_mid_ptr) && (nums[record_right_ptr] == nums[(record_right_ptr - 1)])) //Part
                        {
                            (record_right_ptr--); //Keep updating, traversing

                        } //Part

                        while (((record_mid_ptr + 1) < record_right_ptr) && (nums[record_mid_ptr] == nums[(record_mid_ptr + 1)])) //Part
                        {
                            (record_mid_ptr++); //Keep updating, traversing

                        } //Part

                        (record_right_ptr--); //Keep updating, traversing
                        (record_mid_ptr++); //Keep updating, traversing
                    }

                } //Closed-intervals

                while (((record_left_ptr + 1) < len_nums) && (nums[record_left_ptr] == nums[(record_left_ptr + 1)])) //Part
                {
                    (record_left_ptr++); //Keep updating, traversing

                } //Part

                (record_left_ptr++); //Keep updating, traversing

            } //Left-pointer

            while (((record_trav_ptr + 1) < len_nums) && (nums[record_trav_ptr] == nums[(record_trav_ptr + 1)])) //Part
            {
                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            (record_trav_ptr++); //Keep updating, traversing

        } //Traversal pointer

        return res_vect;
    }
};
