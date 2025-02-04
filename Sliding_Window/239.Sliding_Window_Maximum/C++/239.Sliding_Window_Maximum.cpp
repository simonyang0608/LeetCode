class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th size)                //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record deque /////
        deque<pair<int, int>> record_dq;

        ///// Result vector /////
        vector<int> res_vect;


        /*Dequeue-based loop traversal*/
        ///// Step 1: Looped-traversal for the first fixed-window /////
        for (int nums_idx = 0; (nums_idx < k); (nums_idx++)) //K-th
        {
            while ((! record_dq.empty()) && ((record_dq.back()).first <= nums[nums_idx])) { record_dq.pop_back(); } //Keep updating, popped
                
            record_dq.emplace_back(nums[nums_idx], nums_idx); //Keep updating, recording

        } //K-th

        ///// Step 2: Looped-traversal for the remainings /////
        res_vect.emplace_back((record_dq.front()).first); //Update, Record

        for (int nums_idx = k; (nums_idx < len_nums); (nums_idx++)) //Remains
        {
            while ((! record_dq.empty()) && ((record_dq.front()).second <= (nums_idx - k))) { record_dq.pop_front(); } //Keep updating, popped

            while ((! record_dq.empty()) && ((record_dq.back()).first <= nums[nums_idx])) { record_dq.pop_back(); } //Keep updating, popped

            record_dq.emplace_back(nums[nums_idx], nums_idx); //Keep updating, recording

            res_vect.emplace_back((record_dq.front()).first); //Keep updating, recording

        } //Remains

        return res_vect;
    }
};
