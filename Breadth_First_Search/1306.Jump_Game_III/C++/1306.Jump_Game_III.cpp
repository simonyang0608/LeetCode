class Solution {
public:
    bool canReach(vector<int> & arr, int start) 
    {
        //===================================//
        // Input type:                       //
        //   - vector<int> ref. (arr vector) //
        //   - int (start indexes)           //
        // Return type:                      //
        //   - bool (result flag)            //
        //===================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Current, Previous, Next indexes /////
        int curr_idx, prev_idx, next_idx;

        ///// Record queue /////
        queue<int> record_queue;

        record_queue.push(start);

        ///// Record hashmap, dictionary /////
        unordered_map<int, bool> record_map;

        record_map[start] = true;


        /*Queue-based BFS loop traversal with recorded hashmap, dictionary*/
        while (! record_queue.empty()) //Whole
        {
            curr_idx = record_queue.front(); //Current indexes

            record_queue.pop(); //Popped from front of queue

            ///// Check if the current indexes matched conditions or not /////
            if (! arr[curr_idx]) { return true; }

            prev_idx = (curr_idx - arr[curr_idx]); //Previous indexes
            next_idx = (curr_idx + arr[curr_idx]); //Next indexes

            ///// Check if the previous indexes matched conditions or not /////
            if ((prev_idx >= 0) && (record_map.find(prev_idx) == record_map.end()))
            {
                record_queue.push(prev_idx); //Keep updating, recording

                record_map[prev_idx] = true; //Keep updating, recording
            }
            else { ; }

            ///// Check if the next indexes matched conditions or not /////
            if ((next_idx < len_arr) && (record_map.find(next_idx) == record_map.end()))
            {
                record_queue.push(next_idx); //Keep updating, recording

                record_map[next_idx] = true; //Keep updating, recording
            }
            else { ; }

        } //Whole

        return false;
    }
};
