class Solution {
public:
    string predictPartyVictory(string senate) 
    {
        //============================//
        // Input type:                //
        //   - string (senate string) //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of senate string /////
        int len_senate = senate.size();

        ///// Record queues (i.e. R, D) /////
        queue<int> record_queue_r, record_queue_d;


        /*Queue-based loop traversal*/
        ///// Step 1: Record indexes with queues /////
        for (int senate_idx = 0; (senate_idx < len_senate); (senate_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (senate[senate_idx] == 'R') { record_queue_r.emplace(senate_idx); } //Keep updating, recording
            else { record_queue_d.emplace(senate_idx); } //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded queues /////
        while ((! record_queue_r.empty()) && (! record_queue_d.empty())) //Part
        {
            ///// Check if the current indexes matched conditions or not /////
            if (record_queue_r.front() < record_queue_d.front())
            {
                record_queue_d.pop(); //Keep updating, popped

                record_queue_r.emplace((record_queue_r.front() + len_senate)); //Keep updating, recording

                record_queue_r.pop(); //Keep updating, popped
            }

            else
            {
                record_queue_r.pop(); //Keep updating, popped

                record_queue_d.emplace((record_queue_d.front() + len_senate)); //Keep updating, recording

                record_queue_d.pop(); //Keep updating, popped
            }

        } //Part

        return (! record_queue_r.empty()) ? "Radiant" : "Dire";
    }
};
