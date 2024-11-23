class Solution {
public:
    int maxLength(vector<string> & arr) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<string> ref. (arr vector) //
        // Return type:                         //
        //   - int (result maximun length)      //
        //======================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        return backtrackTraversal(len_arr, 0, arr, ""); //Recursion function call
    }


    int backtrackTraversal(int & len_arr, int slice_idx, vector<string> & arr, string record_str)
    {
        //======================================//
        // Input type:                          //
        //   - int ref. (length of arr vector)  //
        //   - int (sliced-index)               //
        //   - vector<string> ref. (arr vector) //
        //   - string (record string)           //
        // Return type:                         //
        //   - int (result maximun length)      //
        //======================================//
        if (slice_idx >= len_arr) { return record_str.size(); } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record flag /////
        int record_flag = false;

        ///// Current, Record string set /////
        set<char> curr_set_str, record_set_str(record_str.begin(), record_str.end());

        ///// Current string /////
        string curr_str;

        ///// Record, Result maximun length /////
        int record_max_length, res_max_length = record_str.size();


        /*Whole process, flow*/
        for (int record_idx = slice_idx; (record_idx < len_arr); (record_idx++)) //Whole
        {
            curr_str = arr[record_idx]; //Current string
            curr_set_str = set<char>(curr_str.begin(), curr_str.end()); //Current string set

            ///// Check if the current string set matched conditions or not /////
            if (curr_set_str.size() != curr_str.size()) { continue; }

            for (char record_char: curr_str) //Whole
            {
                ///// Check if the current indexed-char existed or not /////
                if (record_set_str.find(record_char) != record_set_str.end())
                {
                    record_flag |= true; //Keep updating, overwriting

                    break;
                }

            } //Whole

            ///// Check if the current flag matched conditions or not /////
            if (! record_flag)
            {
                record_max_length = backtrackTraversal(len_arr, (record_idx + 1), arr, (record_str + curr_str)); //Recursion function call

                ///// Check if the current length is larger or not /////
                if (record_max_length > res_max_length) { res_max_length = record_max_length; }
            }

            ///// Check if the current flag needs to be reset or not /////
            if (record_flag) { record_flag &= false; } //Update, Reset

        } //Whole

        return res_max_length;
    }
};
