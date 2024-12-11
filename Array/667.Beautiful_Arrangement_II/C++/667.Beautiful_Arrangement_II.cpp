class Solution {
public:
    vector<int> constructArray(int n, int k) 
    {
        //=================================//
        // Input type:                     //
        //   - int (n-th value)            //
        //   - int (k-th distincts)        //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 1, record_right_ptr = n;

        ///// Record cycled-times /////
        int record_times = (k - 1);

        ///// Record char /////
        int record_char = 'l';

        ///// Result vector /////
        vector<int> res_vect;


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for cycled-times /////
        while ((record_times--)) //Cycled-times
        {
            ///// Check if the current char matched conditions or not /////
            if (record_char == 'l')
            {
                res_vect.emplace_back((record_left_ptr++)); //Keep updating, recording

                record_char = 'r'; //Keep updating, overwriting
            }
            else
            {
                res_vect.emplace_back((record_right_ptr--)); //Keep updating, recording

                record_char = 'l'; //Keep updating, overwriting
            }

        } //Cycled-times

        ///// Step 2: Post-process, Final completions /////
        while (record_left_ptr <= record_right_ptr) //Remains
        {
            ///// Check if the current char matched conditions or not /////
            if (record_char == 'l')
            {
                res_vect.emplace_back((record_left_ptr++)); //Keep updating, recording
            }
            else
            {
                res_vect.emplace_back((record_right_ptr--)); //Keep updating, recording
            }

        } //Remains

        return res_vect;
    }
};
