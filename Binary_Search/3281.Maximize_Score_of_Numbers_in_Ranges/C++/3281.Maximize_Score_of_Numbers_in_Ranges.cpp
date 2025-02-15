class Solution {
public:
    int maxPossibleScore(vector<int> & start, int d) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (start vector) //
        //   - int (record difference)         //
        // Return type:                        //
        //   - int (result maximun difference) //
        //=====================================//

        /*Initialize*/
        ///// Length of start vector /////
        int len_start = start.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr, record_right_ptr;

        
        /*Binary-search based loop traversal*/
        sort(start.begin(), start.end()); //Sorted operations

        record_left_ptr = 0; record_right_ptr = ((start.back() - start[0]) + d); //Update, Overwrite

        if (len_start == 2) { return record_right_ptr; } //Issue, Boundary-case handling

        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) / 2); //Record middle pointer

            bool record_flag = checkMax(len_start, start, record_mid_ptr, d); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (! record_flag) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool checkMax(const int & len_start, const vector<int> & start, const int & record_val, const int & diff)
    {
        //============================================//
        // Input type:                                //
        //   - cont int ref. (length of start vector) //
        //   - const vector<int> ref. (start vector)  //
        //   - const int ref. (record value)          //
        //   - const int ref. int (record difference) //
        // Return type:                               //
        //   - bool (result flag)                     //
        //============================================//

        /*Initialize*/
        ///// Prefix-value /////
        int prefix_val = start[0];

        /*Whole process, flow*/
        for (int start_idx = 1; (start_idx < len_start); (start_idx++)) //Whole
        {
            ///// Check if the current value matched conditions or not /////
            if (record_val > ((start[start_idx] - prefix_val) + diff)) { return false; }

            prefix_val = max((prefix_val + record_val), start[start_idx]); //Keep updating, overwriting

        } //Whole

        return true;
    }
};
