class Solution {
public:
    int minimumIndex(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result minimun index)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = (len_nums - 1);

        ///// Record dictionary, hashmap (i.e. left, right) /////
        unordered_map<int, int> record_left_map, record_right_map;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Looped-traversal for the suffix-prefix index /////
        while (record_trav_ptr >= 0) //Whole
        {
            ((record_right_map[nums[record_trav_ptr]])++); //Keep updating, recording

            (record_trav_ptr--); //Keep updating, traversing

        } //Whole

        ///// Step 2: Looped-traversal for the prefix-suffix index /////
        (record_trav_ptr++); //Update, Traverse

        while (record_trav_ptr < len_nums) //Whole
        {
            int record_num = nums[record_trav_ptr]; //Record num

            int split_size = (record_trav_ptr + 1); //Split-size

            ((record_right_map[record_num])--); //Keep updating, recording
            ((record_left_map[record_num])++); //Keep updating, recording

            ///// Check if the current indexed-value is majority or not /////
            if ((record_right_map[record_num] > ((len_nums - split_size) / 2)) && (record_left_map[record_num] > (split_size / 2)))
            {
                return record_trav_ptr;
            }
            else { ; }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return (-1);
    }
};
