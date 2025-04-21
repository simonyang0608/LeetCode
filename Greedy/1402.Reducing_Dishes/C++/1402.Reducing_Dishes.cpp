class Solution {
public:
    int maxSatisfaction(vector<int> & satisfaction) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<int> ref. (satisfaction vector) //
        // Return type:                               //
        //   - int (result maximun summary value)     //
        //============================================//

        /*Initialize*/
        ///// Length of satisfaction vector /////
        int len_satisfaction = satisfaction.size();

        ///// Record times, traversal pointer /////
        int record_times = 1, record_trav_ptr = (-1);

        ///// Result maximun summary value /////
        int res_max_sum = 0;


        /*Greedy-based loop traversal*/
        sort(satisfaction.begin(), satisfaction.end()); //Sorted-operations

        ///// Step 1: Looped-traversal for the first summary value /////
        for (int satisfaction_idx = 0; (satisfaction_idx < len_satisfaction); (satisfaction_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (satisfaction[satisfaction_idx] < 0) { continue; }

            ///// Check if the current index is recorded or not /////
            if (record_trav_ptr == (-1)) { record_trav_ptr = satisfaction_idx; } //Keep updating, overwriting
            else { ; }

            res_max_sum += (satisfaction[satisfaction_idx] * (record_times++)); //Keep updating, accumulating

        } //Whole

        ///// Step 2: Looped-traversal for the remainings /////
        if (! res_max_sum) { return 0; } //Issue, Boundary-case handling

        for (int satisfaction_idx = (record_trav_ptr - 1); (satisfaction_idx >= 0); (satisfaction_idx--)) //Whole
        {
            int curr_sum_val = BoundSum(len_satisfaction, satisfaction, satisfaction_idx); //Current summary value

            res_max_sum = (curr_sum_val > res_max_sum) ? curr_sum_val : res_max_sum; //Keep updating, overwriting

        } //Whole

        return res_max_sum;
    }


    int BoundSum(const int & len_satisfaction, const vector<int> & satisfaction, const int & record_val)
    {
        //====================================================//
        // Input type:                                        //
        //   - const int ref. (length of satisfaction vector) //
        //   - const vector<int> ref. (satisfaction vector)   //
        //   - const int ref. (record value)                  //
        // Return type:                                       //
        //   - int (result summary value)                     //
        //====================================================//

        /*Initialize*/
        ///// Record times /////
        int record_times = 1;

        ///// Result summary value /////
        int res_sum_val = 0;


        /*Whole process, flow*/
        for (int satisfaction_idx = record_val; (satisfaction_idx < len_satisfaction); (satisfaction_idx++)) //Whole
        {
            res_sum_val += (satisfaction[satisfaction_idx] * (record_times++)); //Keep updating, accumulating

        } //Whole

        return res_sum_val;
    }
};
