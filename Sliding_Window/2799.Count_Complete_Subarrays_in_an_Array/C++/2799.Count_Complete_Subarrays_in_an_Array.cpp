class Solution {
public:
    int countCompleteSubarrays(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result summary counter)   //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector, set /////
        int len_nums = nums.size(), len_set = (-1);

        ///// Record set /////
        set<int> record_set(nums.begin(), nums.end());

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        len_set = record_set.size(); //Update, Overwrite

        while (record_right_ptr < len_nums) //Whole
        {
            ((record_map[nums[record_right_ptr]])++); //Keep updating, recording

            while (record_map.size() >= len_set) //Part
            {
                res_cnter += (len_nums - record_right_ptr); //Keep updating, accumulating

                ((record_map[nums[record_left_ptr]])--); //Keep updating, recording

                ///// Check if the current summary counter matched conditions or not /////
                if (! record_map[nums[record_left_ptr]]) { record_map.erase(nums[record_left_ptr]); } //Keep updating, delete
                else { ; }

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_cnter;
    }
};
