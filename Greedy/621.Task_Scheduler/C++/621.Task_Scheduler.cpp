class Solution {
public:
    int leastInterval(vector<char> & tasks, int n) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<char> ref. (tasks vector)     //
        //   - int (n-th interval)                  //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of tasks vector /////
        int len_tasks = tasks.size();

        ///// Record vector /////
        vector<int> record_vect(26, 0);

        ///// Record maximun value /////
        int record_max_val = 0;

        ///// Maximun value summary counter /////
        int max_val_cnter = 0;


        /*Greedy-based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-char with vector /////
        for (int tasks_idx = 0; (tasks_idx < len_tasks); (tasks_idx++)) //Whole
        {
            ((record_vect[(tasks[tasks_idx] - 'A')])++); //Keep updating, accumulating

            record_max_val = (record_vect[(tasks[tasks_idx] - 'A')] > record_max_val) ? 
                              record_vect[(tasks[tasks_idx] - 'A')] : record_max_val; //Keep updating, overwriting

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector
        for (int record_idx = 0; (record_idx < 26); (record_idx++)) //Whole
        {
            ///// Check if the current summary counter is maximun or not /////
            if (record_vect[record_idx] == record_max_val) { (max_val_cnter++); } //Keep updating, accumulating
            else { ; }

        } //Whole

        return max((((record_max_val - 1) * (n + 1)) + max_val_cnter), len_tasks);
    }
};
