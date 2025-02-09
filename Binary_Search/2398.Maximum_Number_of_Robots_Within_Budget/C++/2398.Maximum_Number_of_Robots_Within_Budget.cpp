class Solution {
public:
    int maximumRobots(vector<int> & chargeTimes, vector<int> & runningCosts, long long budget) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<int> ref. (chargeTimes vector)  //
        //   - vector<int> ref. (runningCosts vector) //
        //   - long long (budget value)               //
        // Return type:                               //
        //   - int (result maximun window-size)       //
        //============================================//

        /*Initialize*/
        ///// Length of chargeTimes vector /////
        int len_chargeTimes = chargeTimes.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = len_chargeTimes;


        /*Binary-search based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) / 2); //Record middle pointer

            bool record_flag = kthBudget(len_chargeTimes, chargeTimes, runningCosts, budget, record_mid_ptr); //Record flag

            ///// Check if the current window-size exceed boundary or not /////
            if (! record_flag) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool kthBudget(const int & len_chargeTimes, const vector<int> & chargeTimes, const vector<int> & runningCosts, const long long & budget, const int & record_val)
    {
        //===================================================//
        // Input type:                                       //
        //   - const int ref. (length of chargeTimes vector) //
        //   - const vector<int> ref. (chargeTimes vector)   //
        //   - const vector<int> ref. (runningCosts vector)  //
        //   - connst long long ref. (budget value)          //
        //   - const int ref. (record-value)                 //
        // Return type:                                      //
        //   - bool (result flag)                            //
        //===================================================//

        /*Initialize*/
        ///// Record deque /////
        deque<pair<int, int>> record_dq;

        ///// Result summary value /////
        long long res_sum_val = 0;


        /*Whole process, flow*/
        ///// Step 1: Looped-traversal for the first fixed-window size /////
        for (int chargeTimes_idx = 0; (chargeTimes_idx < record_val); (chargeTimes_idx++)) //Fixed-window size
        {
            while ((! record_dq.empty()) && ((record_dq.back()).first < chargeTimes[chargeTimes_idx])) { record_dq.pop_back(); } //Keep updating, popped

            record_dq.emplace_back(chargeTimes[chargeTimes_idx], chargeTimes_idx); //Keep updating, recording

            res_sum_val += runningCosts[chargeTimes_idx]; //Keep updating, accumulating

        } //Fixed-window size

        ///// Step 2: Looped-traversal for the remainings /////
        if (((record_dq.front()).first + (record_val * res_sum_val)) <= budget) { return true; } //Issue, Boundary-case handling

        for (int chargeTimes_idx = record_val; (chargeTimes_idx < len_chargeTimes); (chargeTimes_idx++)) //Remainings
        {
            res_sum_val -= runningCosts[(chargeTimes_idx - record_val)]; //Keep updating, reducing

            ///// Check if the front index exceed pre-window size or not /////
            if ((record_dq.front()).second <= (chargeTimes_idx - record_val)) { record_dq.pop_front(); } //Keep updating, popped
            else { ; }

            while ((! record_dq.empty()) && ((record_dq.back()).first < chargeTimes[chargeTimes_idx])) { record_dq.pop_back(); } //Keep updating, popped

            record_dq.emplace_back(chargeTimes[chargeTimes_idx], chargeTimes_idx); //Keep updating, recording

            res_sum_val += runningCosts[chargeTimes_idx]; //Keep updating, accumulating

            if (((record_dq.front()).first + (record_val * res_sum_val)) <= budget) { return true; } //Issue, Boundary-case handling

        } //Remainings

        return false;
    }
};
