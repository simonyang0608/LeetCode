class Solution {
public:
    int pivotIndex(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result index)             //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record vector /////
        vector<int> record_vect((len_nums + 1), 0);


        /*Prefix-summary based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-value with vector /////
        for (int record_idx = 1; (record_idx <= len_nums); (record_idx++)) //Whole
        {
            record_vect[record_idx] = (record_vect[(record_idx - 1)] + nums[(record_idx - 1)]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        for (int record_idx = 1; (record_idx <= len_nums); (record_idx++)) //Whole
        {
            ///// Check if the current differences matched conditions or not /////
            if (record_vect[(record_idx - 1)] == (record_vect[len_nums] - record_vect[record_idx])) { return (record_idx - 1); }

        } //Whole

        return (-1);
    }
};
