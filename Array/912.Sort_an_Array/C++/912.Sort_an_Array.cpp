class Solution {
public:
    vector<int> sortArray(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record root index /////
        int record_root_idx = 0;


        /*Heap-sort based loop traversal*/
        ///// Step 1: Looped-traversal for bottom-up tree-nodes /////
        for (int record_idx = ((len_nums - 1) / 2); (record_idx >= 0); (record_idx--)) //Bottom-up
        {
            heapSort(nums, record_idx, len_nums); //Recursion function call (i.e. Bottom-up)

        } //Bottom-up

        ///// Step 2: Post-process, Final completions /////
        for (int record_idx = (len_nums - 1); (record_idx >= 1); (record_idx--)) //Whole
        {
            swap(nums[0], nums[record_idx]); //Keep updating, swapped

            heapSort(nums, record_root_idx, record_idx); //Recursion function call

        } //Whole

        return nums;
    }


    void heapSort(vector<int> & nums, int & record_large_idx, int & len_nums)
    {
        //============================================//
        // Input type:                                //
        //   - vector<int> ref. (nums vector)         //
        //   - int ref. (record large, maximun index) //
        //   - int ref. (length of nums vector)       //
        // Return type:                               //
        //   - void (no return)                       //
        //============================================//

        /*Initialize*/
        ///// Record indexes (i.e. left, right) /////
        int record_left_idx = ((record_large_idx * 2) + 1), record_right_idx = ((record_large_idx * 2) + 2);

        ///// Result large, maximun index /////
        int res_large_idx = record_large_idx;


        /*Whole process, flow*/
        ///// Check if the current indexed-value is larger or not /////
        if ((record_left_idx < len_nums) && (nums[record_left_idx] >= nums[res_large_idx])) { res_large_idx = record_left_idx; } //Keep updating, overwriting
        else { ; }

        if ((record_right_idx < len_nums) && (nums[record_right_idx] >= nums[res_large_idx])) { res_large_idx = record_right_idx; } //Keep updating, overwriting
        else { ; }

        ///// Check if the current indexed-value matched conditions or not /////
        if (res_large_idx != record_large_idx) { swap(nums[record_large_idx], nums[res_large_idx]);  heapSort(nums, res_large_idx, len_nums); } //Recursion function call

        return;
    }
};
