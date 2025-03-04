class Solution {
public:
    long long maxScore(vector<int> & nums1, vector<int> & nums2, int k) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (nums1 vector)  //
        //   - vector<int> ref. (nums2 vector)  //
        //   - int (k-th length)                //
        // Return type:                         //
        //   - long long (result maximun score) //
        //======================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums1.size();

        ///// Record vector /////
        vector<pair<int, int>> record_vect;

        ///// Record heap, priority-queue /////
        priority_queue<int, vector<int>, greater<int>> record_pq;

        ///// Record score /////
        long long record_score = 0;

        ///// Result maximun score /////
        long long res_max_score = 0;


        /*Heap, Priority-queue based loop traversal with sorted-operations*/
        ///// Step 1: Record indexed-value informations /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_vect.emplace_back(nums2[nums_idx], nums1[nums_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the first fixed-window size /////
        sort(record_vect.rbegin(), record_vect.rend()); //Sorted-operations

        for (int record_idx = 0; (record_idx < k); (record_idx++)) //Fixed-window size
        {
            record_score += (record_vect[record_idx]).second; //Keep updating, accumulating

            record_pq.emplace((record_vect[record_idx]).second); //Keep updating, recording

        } //Fixed-window size

        ///// Step 3: Looped-traversal for the remainings /////
        res_max_score = max(res_max_score, (record_score * (record_vect[(k - 1)]).first)); //Update, Overwrite

        for (int record_idx = k; (record_idx < len_nums); (record_idx++)) //Remainings
        {
            record_score -= record_pq.top(); record_pq.pop(); //Keep updating, reducing

            record_score += (record_vect[record_idx]).second; //Keep updating, accumulating

            record_pq.emplace((record_vect[record_idx]).second); //Keep updating, recording

            res_max_score = max(res_max_score, (record_score * (record_vect[record_idx]).first)); //Keep updating, overwriting

        } //Remainings

        return res_max_score;
    }
};
