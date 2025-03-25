class Solution {
public:
    vector<string> summaryRanges(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - vector<string> (result vector) //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result vector /////
        vector<string> res_vect;


        /*Greedy-based loop traversal*/
        while (record_trav_ptr < len_nums) //Whole
        {
            string start_str = to_string(nums[record_trav_ptr]); //Start-string

            while (((record_trav_ptr + 1) < len_nums) && (nums[(record_trav_ptr + 1)] == (nums[record_trav_ptr] + 1))) //Part
            {
                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            string end_str = to_string(nums[record_trav_ptr]); //End-string

            ///// Check if the start is the same as end-string or not /////
            if (start_str == end_str) { res_vect.emplace_back(start_str); } //Keep updating, recording
            else { res_vect.emplace_back((start_str + "->" + end_str)); } //Keep updating, recording

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_vect;
    }
};
