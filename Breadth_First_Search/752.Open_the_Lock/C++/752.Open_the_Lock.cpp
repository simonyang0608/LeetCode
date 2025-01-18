class Solution {
public:
    int openLock(vector<string> & deadends, string target) 
    {
        //===========================================//
        // Input type:                               //
        //   - vector<string> ref. (deadends vector) //
        //   - string (target string)                //
        // Return type:                              //
        //   - int (result minimun steps)            //
        //===========================================//

        /*Initialize*/
        ///// Length of deadends vector /////
        int len_deadends = deadends.size();

        ///// Record queue /////
        queue<string> record_queue;

        ///// Record dictionary, hashmap /////
        map<string, bool> record_map;

        ///// Result minimun steps /////
        int res_min_step = 0;


        /*Breath-first search based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-string with dictionary, hashmap /////
        for (int deadends_idx = 0; (deadends_idx < len_deadends); (deadends_idx++)) //Whole
        {
            record_map[deadends[deadends_idx]] = true; //Keep updating, recording

        } //Whole

        if (record_map["0000"]) { return (-1); } //Issue, Boundary-case handling

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        record_map["0000"] = true; //Update, Record

        record_queue.emplace("0000"); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                string record_str = record_queue.front(); record_queue.pop(); //Record string

                ///// Check if the current string reach target or not /////
                if (record_str == target) { return res_min_step; }

                for (int record_idx = 0; (record_idx < 4); (record_idx++)) //String-size
                {
                    string next_str1 = (record_str.substr(0, record_idx) + ((record_str[record_idx] == '9') ? "0" : (to_string(((record_str[record_idx] - '0') + 1)))) + record_str.substr((record_idx + 1), (4 - record_idx))); //Next string-1

                    string next_str2 = (record_str.substr(0, record_idx) + ((record_str[record_idx] == '0') ? "9" : to_string(((record_str[record_idx] - '0') - 1))) + record_str.substr((record_idx + 1), (4 - record_idx))); //Next string-2

                    ///// Check if the current string existed or not /////
                    if (! record_map[next_str1]) { record_queue.emplace(next_str1); record_map[next_str1] = true; } //Keep updating, recording
                    else { ; }

                    if (! record_map[next_str2]) { record_queue.emplace(next_str2); record_map[next_str2] = true; } //Keep updating, recording
                    else { ; }

                } //String-size

            } //Queue-size

            (res_min_step++); //Keep updating, accumulating

        } //Cycled-times

        return (-1);
    }
};
