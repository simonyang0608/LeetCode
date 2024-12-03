class Solution {
public:
    int garbageCollection(vector<string> & garbage, vector<int> & travel) 
    {
        //==================================//
        // Input type:                      // 
        //   - vector<string> ref. garbage  //
        //   - vector<int> ref. travel      //
        // Return type:                     //
        //   - int (result minimun minutes) //
        //==================================//

        /*Initialize*/
        ///// Length of vector (i.e. garbage, travel) /////
        int len_garbage = garbage.size(), len_travel = travel.size();

        ///// Record max-index (i.e. paper, glass, metal) /////
        int record_max_pidx = 0, record_max_gidx = 0, record_max_midx = 0;

        ///// Record summary counter (i.e. paper, glass, metal) /////
        int record_p_cnter = 0, record_g_cnter = 0, record_m_cnter = 0;

        ///// Record flag (i.e. paper, glass, metal) /////
        bool record_p_flag = false, record_g_flag = false, record_m_flag = false;

        ///// Record indexed-string /////
        string record_str;

        ///// Result maximun minutes, time /////
        int res_max_time = 0;


        /*Greedy-based loop traversal with recorded prefix-summary vector*/
        ///// Step 1: Record prefix-summary value with vector /////
        for (int travel_idx = 1; (travel_idx < len_travel); (travel_idx++)) //Prefix-part, half
        {
            travel[travel_idx] += travel[(travel_idx - 1)]; //Keep updating, overwriting

        } //Prefix-part, half

        ///// Step 2: Looped-traversal for recorded prefix-summary vector /////
        for (int garbage_idx = 0; (garbage_idx < len_garbage); (garbage_idx++)) //Whole
        {
            record_str = garbage[garbage_idx]; //Record string

            for (char record_char: record_str) //Indexed-string
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if (record_char == 'P')
                { 
                    (record_p_cnter++); //Keep updating, accumulating

                    ///// Check if the current flag matched conditions or not /////
                    if (! record_p_flag) { record_max_pidx = garbage_idx; record_p_flag |= true; } //Keep updating, overwriting
                    else { ; }
                }
                else { ; }

                if (record_char == 'G')
                { 
                    (record_g_cnter++); //Keep updating, accumulating

                    ///// Check if the current flag matched conditions or not /////
                    if (! record_g_flag) { record_max_gidx = garbage_idx; record_g_flag |= true; } //Keep updating, overwriting
                    else { ; }
                }
                else { ; }

                if (record_char == 'M')
                { 
                    (record_m_cnter++); //Keep updating, accumulating

                    ///// Check if the current flag matched conditions or not /////
                    if (! record_m_flag) { record_max_midx = garbage_idx; record_m_flag |= true; } //Keep updating, overwriting
                    else { ; }
                }
                else { ; }

            } //Indexed-string

            ///// Check if the current flag needs to be reset or not /////
            if (record_p_flag) { record_p_flag &= false; } //Update, Reset
            else { ; }

            if (record_g_flag) { record_g_flag &= false; } //Update, Reset
            else { ; }

            if (record_m_flag) { record_m_flag &= false; } //Update, Reset
            else { ; }

        } //Whole

        ///// Step 3: Post-process, Final completions /////
        if (record_max_pidx) { res_max_time += travel[(record_max_pidx - 1)]; } //Update, Accumulate
        else { ; }

        if (record_max_gidx) { res_max_time += travel[(record_max_gidx - 1)]; } //Update, Accumulate
        else { ; }

        if (record_max_midx) { res_max_time += travel[(record_max_midx - 1)]; } //Update, Accumulate
        else { ; }

        res_max_time += (record_p_cnter + record_g_cnter + record_m_cnter); //Update, Accumulate

        return res_max_time;
    }
};
