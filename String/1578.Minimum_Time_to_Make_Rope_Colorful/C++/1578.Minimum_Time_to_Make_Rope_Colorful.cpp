class Solution {
public:
    int minCost(string colors, vector<int> & neededTime) 
    {
        //==========================================//
        // Input type:                              // 
        //   - string (colors string)               //
        //   - vector<int> ref. (neededTime vector) //
        // Return type:                             //
        //   - int (result minimun cost times)      //
        //==========================================//

        /*Initialize*/
        ///// Length of colors string /////
        int len_colors = colors.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record maximun values, next time /////
        int record_max_val, record_next_time;

        ///// Result minimun summary times /////
        int res_sum_times = 0;


        /*Greedy-based loop traversal*/
        while (record_trav_ptr < len_colors) //Whole
        {
            record_max_val = neededTime[record_trav_ptr]; //Keep updating, overwriting

            while (((record_trav_ptr + 1) < len_colors) && (colors[record_trav_ptr] == colors[(record_trav_ptr + 1)])) //Part
            {
                record_next_time = neededTime[(record_trav_ptr + 1)]; //Keep updating, overwriting

                ///// Check if the current indexed-value is larger or not /////
                if (record_max_val >= record_next_time)
                {
                    res_sum_times += record_next_time; //Keep updating, accumulating
                }

                else
                {
                    res_sum_times += record_max_val; //Keep updating, accumulating

                    record_max_val = record_next_time; //Keep updating, overwriting
                }

                (record_trav_ptr++); //Keep updating, accumulating

            } //Part

            (record_trav_ptr++); //Keep updating, accumulating

        } //Whole

        return res_sum_times;
    }
};
