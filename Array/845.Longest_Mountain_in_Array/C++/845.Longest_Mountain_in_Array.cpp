class Solution {
public:
    int longestMountain(vector<int> & arr) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (arr vector)        //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record summary (i.e. induce, reduce) /////
        int record_induce_sum = 0, record_reduce_sum = 0;

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Greedy-based loop traversal*/
        while (record_trav_ptr < (len_arr - 1)) //Whole
        {
            while (((record_trav_ptr + 1) < len_arr) && (arr[(record_trav_ptr + 1)] > arr[record_trav_ptr])) //Increase
            {
                (record_induce_sum++); //Keep updating, accumulating
                (record_trav_ptr++); //Keep updating, traversing
              
            } //Increase

            while (((record_trav_ptr + 1) < len_arr) && (arr[(record_trav_ptr + 1)] < arr[record_trav_ptr])) //Decrease
            {
                (record_reduce_sum++); //Keep updating, accumulating
                (record_trav_ptr++); //Keep updating, traversing
              
            } //Decrease

            ///// Check if the current summary matched conditions or not /////
            if (record_induce_sum && record_reduce_sum) { res_max_cnter = max(res_max_cnter, ((record_induce_sum + record_reduce_sum) + 1)); } //Keep updating, overwriting
            else { ; }

            ///// Check if the current summary needs to be reset or not /////
            if (record_induce_sum) { record_induce_sum &= 0; } //Update, Reset
            else { ; }

            if (record_reduce_sum) { record_reduce_sum &= 0; } //Update, Reset
            else { ; }

            while (((record_trav_ptr + 1) < len_arr) && (arr[(record_trav_ptr + 1)] == arr[record_trav_ptr])) { (record_trav_ptr++); } //Keep updating, traversing

        } //Whole

        return res_max_cnter;
    }
};
