class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> & prerequisites) 
    {
        //=====================================================//
        // Input type:                                         //
        //   - int (number of courses)                         //
        //   - vector<vector<int>> ref. (prerequisites vector) //
        // Return type:                                        //
        //   - vector<int> (result vector)                     //
        //=====================================================//

        /*Initialize*/
        ///// Length of queue, prerequisites vector /////
        int len_record_queue, len_prerequisites = prerequisites.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<int>> record_map;

        ///// Record vector /////
        vector<int> record_vect(numCourses, 0);

        ///// Record queue /////
        queue<int> record_queue;

        ///// Record value /////
        int record_val;

        ///// Result vector /////
        vector<int> res_vect;


        /*Breath-first search based loop traversal with recorded queue*/
        ///// Step 1: Record indexed-value with vector, dictionary, hashmap /////
        for (int prerequisites_idx = 0; (prerequisites_idx < len_prerequisites); (prerequisites_idx++)) //Whole
        {
            (record_map[(prerequisites[prerequisites_idx])[1]]).emplace_back((prerequisites[prerequisites_idx])[0]); //Keep updating, recording

            ((record_vect[(prerequisites[prerequisites_idx])[0]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Record indexed-value with queue /////
        for (int record_idx = 0; (record_idx < numCourses); (record_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (! record_vect[record_idx]) { record_queue.push(record_idx); } //Keep updating, recording
            else { ; }

        } //Whole

        ///// Step 3: Looped-traversal with recorded queue /////
        while (! record_queue.empty()) //Cycled-times
        {
            len_record_queue = record_queue.size(); //Update, Overwrite

            numCourses -= len_record_queue; //Update, Reduce

            for (int record_idx = 0; (record_idx < len_record_queue); (record_idx++)) //Times
            {
                record_val = record_queue.front(); //Keep updating, overwriting

                res_vect.emplace_back(record_val); //Keep updating, recording

                for (int & next_val: record_map[record_val]) //Whole
                {
                    ///// Check if the current indexed-value matched conditions or not /////
                    if (! record_vect[next_val]) { continue; }

                    if (! (--(record_vect[next_val]))) { record_queue.push(next_val); } //Keep updating, recording
                    else { ; }
                }

                record_queue.pop(); //Keep updating, popped

            } //Times

        } //Cycled-times

        if (! numCourses) { return res_vect; }

        return {};
    }
};
