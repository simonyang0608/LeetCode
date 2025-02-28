class Solution {
public:
    int videoStitching(vector<vector<int>> & clips, int time) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (clips vector) //
        //   - int (time-value)                        //
        // Return type:                                //
        //   - int (result summary counter)            //
        //=============================================//

        /*Initialize*/
        ///// Length of clips vector /////
        int len_clips = clips.size();

        ///// Record start value /////
        int record_start = 0;

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result maximun value /////
        int res_max_val = (-1);

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Greedy-based looped-traversal with sorted operations*/
        sort(clips.begin(), clips.end()); //Sorted operations

        while (record_start < time) //Times
        {
            while ((record_trav_ptr < len_clips) && (record_start >= (clips[record_trav_ptr])[0])) //Part
            {
                res_max_val = ((clips[record_trav_ptr])[1] > res_max_val) ? (clips[record_trav_ptr])[1] : res_max_val; //Keep updating, overwriting

                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            ///// Check if the current start-value exceed boundary or not /////
            if (record_start >= res_max_val) { return (-1); }

            record_start = res_max_val; //Keep updating, overwriting

            (res_cnter++); //Keep updating, accumulating

        } //Times

        return (record_start >= time) ? res_cnter : (-1);
    }
};
