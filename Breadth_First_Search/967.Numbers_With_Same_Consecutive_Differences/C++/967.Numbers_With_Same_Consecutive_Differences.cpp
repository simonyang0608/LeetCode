class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        //=================================//
        // Input type:                     //
        //   - int (n-th length)           //
        //   - int (k-th difference)       //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Visit dictionary, hashmap /////
        map<string, bool> visit_map;

        ///// Result vector /////
        vector<int> res_vect;


        /*Queue-based BFS loop traversal*/
        for (int digit_idx = 1; (digit_idx <= 9); (digit_idx++)) //Whole
        {
            queue<string> record_queue; record_queue.emplace(to_string(digit_idx)); //Keep updating, recording

            bfsTraversal(visit_map, record_queue, res_vect, n, k); //BFS function call

        } //Whole

        return res_vect;
    }


    void bfsTraversal(map<string, bool> & visit_map, queue<string> & record_queue, vector<int> & res_vect, 
                      const int & n, const int & k)
    {
        //========================================================//
        // Input type:                                            //
        //   - map<string, bool> ref. (visit dictionary, hashmap) //
        //   - queue<string> ref. (record queue)                  //
        //   - vector<int> ref. (result vector)                   //
        //   - const int ref. (n-th length)                       //
        //   - const int ref. (k-th difference)                   //
        // Return type:                                           //
        //   - void (no return)                                   //
        //========================================================//

        /*Whole process, flow*/
        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                string record_str = record_queue.front(); record_queue.pop(); //Keep updating, popped

                ///// Check if the current string is visited or not /////
                if (visit_map[record_str]) { continue; }

                visit_map[record_str] = true; //Keep updating, recording

                ///// Check if the current string matched conditions or not /////
                if (record_str.size() >= n) { res_vect.emplace_back(stoi(record_str)); continue; }

                int record_val = (record_str.back() - '0'); //Record value

                int next_decr_val = (record_val - k); int next_incr_val = (record_val + k); //Next value (i.e. decrease, increase)

                ///// Check if the next digit is valid or not /////
                if (next_decr_val >= 0) { record_queue.emplace((record_str + to_string(next_decr_val))); } //Keep updating, recording
                else { ; }

                if (next_incr_val <= 9) { record_queue.emplace((record_str + to_string(next_incr_val))); } //Keep updating, recording
                else { ; }

            } //Queue-size

        } //Cycled-times
    }
};
