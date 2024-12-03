class Solution {
public:
    int maximumProduct(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th operations)          //
        // Return type:                       //
        //   - int (result maximun product)   //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record priority-queue /////
        priority_queue<int, vector<int>, greater<int>> record_pq;

        ///// Record module /////
        int record_module = (1e9 + 7);

        ///// Result maximun product /////
        long long res_max_prod = 1;


        /*Priority-queue based loop traversal*/
        ///// Step 1: Looped-traversal, Update for heap-push elements /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_pq.push(nums[nums_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal, Update for heap-pop, push elements /////
        for (int k_idx = 0; (k_idx < k); (k_idx++)) //K-th times
        {
            record_pq.push((record_pq.top() + 1)); ////Keep updating, recording
            record_pq.pop(); //Keep updating, popped

        } ////K-th times

        ///// Step 3: Post-process, Final completions /////
        while ((! record_pq.empty())) //Whole
        {
            res_max_prod = ((res_max_prod * record_pq.top()) % record_module); //Keep updating, overwriting

            record_pq.pop(); //Keep updating, popped

        } //Whole

        return (int)(res_max_prod);
    }
};
