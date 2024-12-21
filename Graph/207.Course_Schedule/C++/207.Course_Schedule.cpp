class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> & prerequisites)
    {
        //=====================================================//
        // Input type:                                         //
        //   - int (number of courses)                         //
        //   - vector<vector<int>> ref. (prerequisites vector) //
        // Return type:                                        //
        //   - bool (result flag)                              //
        //=====================================================//
        
        /*Initialize*/
        ///// Length of queue, prerequisites vector /////
        int len_record_queue, len_prerequisites = prerequisites.size();

        ///// Record vector /////
        vector<int> record_vect(numCourses, 0);

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<int>> record_map;

        ///// Record queue /////
        queue<int> record_queue;

        ///// Record value /////
        int record_val;


        /*Breath-first search based loop traversal with recorded queue*/
        ///// Step 1: Record indexed-value with vector, dictionary, hashmap /////
        for (int prerequisites_idx = 0; (prerequisites_idx < len_prerequisites); (prerequisites_idx++)) //Whole
        {
            (record_map[(prerequisites[prerequisites_idx])[1]]).emplace_back((prerequisites[prerequisites_idx])[0]); //Keep updating, recording

            ((record_vect[(prerequisites[prerequisites_idx])[0]])++); //Keep updating, accumulating

        } //Whole

        ///// Step 2: Looped-traversal with recorded queue /////
        for (int record_idx= 0 ; (record_idx < numCourses); (record_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (! record_vect[record_idx]) { record_queue.push(record_idx); } //Keep updating, recording
            else { ; }

        } //Whole

        ///// Step 3: Post-process, Final completions /////
        while (! record_queue.empty()) //Cycled-times
        {
            len_record_queue = record_queue.size(); //Update, Overwrite

            numCourses -= len_record_queue; //Update, Reduce

            for (int queue_idx = 0; (queue_idx < len_record_queue); (queue_idx++)) //Times
            {
                record_val = record_queue.front(); //Record value
 
                for (int & record_node: record_map[record_val]) //Whole
                {
                    ///// Check if the current indexed-value matched conditions or not /////
                    if (! record_vect[record_node]) { continue; }

                    if (! (--(record_vect[record_node]))) { record_queue.push(record_node); } //Keep updating, recording
                    else { ; }

                } //Whole

                record_queue.pop(); //Keep updating, popped

            } //Times

        } //Cycled-times

        return (! numCourses) ? true : false;
    }
};
