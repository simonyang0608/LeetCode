class Solution {
public:
    int lastStoneWeight(vector<int> & stones) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (stones vector) //
        // Return type:                         //
        //   - int (result weight)              //
        //======================================//

        /*Initialize*/
        ///// Record heap, priority-queue /////
        priority_queue<int> record_pq(stones.begin(), stones.end());

        ///// Record values (i.e. first, second) /////
        int record_fst_val, record_scnd_val;


        /*Heap, priority-queue based loop traversal*/
        while (record_pq.size() >= 2) //Cycled-times
        {
            record_scnd_val = record_pq.top(); //Record second value

            record_pq.pop(); //Keep updating, popped

            record_fst_val = record_pq.top(); //Record first value

            record_pq.pop(); //Keep updating, popped

            ///// Check if the current indexed-value matched conditions or not /////
            if (record_fst_val == record_scnd_val) { ; }
            else { record_pq.push((abs(record_fst_val - record_scnd_val))); } //Keep updating, pushed

        } //Cycled-times

        return (record_pq.empty()) ? 0 : record_pq.top();

    }
};
