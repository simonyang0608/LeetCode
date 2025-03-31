class Solution {
public:
    int sumSubarrayMins(vector<int> & arr) 
    {
        //===================================//
        // Input type:                       //
        //   - vector<int> ref. (arr vector) //
        // Return type:                      //
        //   - int (result summary value)    //
        //===================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record stack /////
        stack<int> record_stack;

        ///// Record module /////
        int record_module = (1e9 + 7);

        ///// Result summary value /////
        long long res_sum_val = 0;


        /*Stack-based loop traversal*/
        arr.emplace_back(0); //Update, Record

        for (int arr_idx = 0; (arr_idx <= len_arr); (arr_idx++)) //Whole
        {
            while ((! record_stack.empty()) && (arr[arr_idx] < arr[record_stack.top()])) //Part
            {
                int record_idx = record_stack.top(); record_stack.pop(); //Record index

                int prev_idx = (record_stack.empty()) ? (-1) : record_stack.top(); //Previous index

                res_sum_val += (arr[record_idx] * static_cast<long long>(arr_idx - record_idx) * 
                                static_cast<long long>(record_idx - prev_idx)); //Keep updating, accumulating

                res_sum_val %= record_module; //Keep updating, moduling

            } //Part

            record_stack.emplace(arr_idx); //Keep updating, recording

        } //Whole

        return res_sum_val;
    }
};
