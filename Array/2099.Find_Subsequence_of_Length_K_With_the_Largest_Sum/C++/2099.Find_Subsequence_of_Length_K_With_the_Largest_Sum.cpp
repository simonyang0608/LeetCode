class Solution {
public:
    vector<int> maxSubsequence(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th quantities)          //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, int>> record_pq;

        ///// Record vector /////
        vector<int> record_vect(len_nums, ((-2) * (1e5)));

        ///// Result vector /////
        vector<int> res_vect;


        /*Heap, Priority-queue based loop traversal*/
        ///// Step 1: Record indexed-value with heap, priority-queue /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_pq.push(make_pair(((-1) * nums[nums_idx]), nums_idx)); //Keep updating, recording

            ///// Check if the current size is larger than k-th or not /////
            if (record_pq.size() > k) { record_pq.pop(); } //Keep updating, popped
            else { ; }
             
        } //Whole

        ///// Step 2: Looped-traversal with recorded heap, priority-queue /////
        while (! record_pq.empty()) //Remains
        {
            record_vect[(record_pq.top().second)] = ((-1) * (record_pq.top()).first); //Keep updating, overwriting

            record_pq.pop(); //Keep updating, popped

        } //Remains

        ///// Step 3: Post-process, Final completions /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (record_vect[nums_idx] != ((-2) * (1e5))) { res_vect.emplace_back(record_vect[nums_idx]); } //Keep updating, recording
            else { ; }

        } //Whole

        return res_vect;
    }
};
