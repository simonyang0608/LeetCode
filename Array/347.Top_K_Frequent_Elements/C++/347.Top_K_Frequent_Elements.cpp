class Solution {
public:
    vector<int> topKFrequent(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th numbers)             //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        nums.emplace_back(10001);

        int len_nums = nums.size();

        ///// Sorted operations /////
        sort(nums.begin(), nums.end());

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record previous value, index /////
        int record_prev_val = nums[0], record_prev_idx = 0;

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, int>> record_pq;

        ///// Result vector /////
        vector<int> res_vect;


        /*Heap, Priority-queue based loop traversal*/
        ///// Step 1: Record indexed-value with heap, priority-queue /////
        while (record_trav_ptr < len_nums) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_trav_ptr] != record_prev_val)
            {
                record_pq.push(make_pair((record_trav_ptr - record_prev_idx), record_prev_val)); //Keep updating, recording

                record_prev_val = nums[record_trav_ptr]; //Keep updating, overwriting
                record_prev_idx = record_trav_ptr; //Keep updating, overwriting
            }
            else { ; }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        ///// Step 2: Post-process, Final completions /////
        for (int k_idx = 0; (k_idx < k); (k_idx++)) //K-th times
        {
            res_vect.emplace_back((record_pq.top()).second); //Keep updating, recording

            record_pq.pop(); //Keep updating, popped

        } //K-th times

        return res_vect;
    }
};
