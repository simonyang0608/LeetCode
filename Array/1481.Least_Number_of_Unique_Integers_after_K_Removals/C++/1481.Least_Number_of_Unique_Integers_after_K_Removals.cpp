class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> & arr, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (arr vector)        //
        //   - int (k-th elements)                  //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record heap, priority-queue /////
        priority_queue<int, vector<int>, greater<int>> record_pq;


        /*Heap, priority-queue based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-values informations with dictionary, hashmap /////
        for (int arr_idx = 0; (arr_idx < len_arr); (arr_idx++)) //Whole
        {
            ((record_map[arr[arr_idx]])++); //Keep updating, accumulating

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (auto record_ele = record_map.cbegin(); (record_ele != record_map.cend()); (record_ele++)) //Whole
        {
            record_pq.emplace((record_ele->second)); //Keep updating, recording

        } //Whole

        while (k > 0) //K-th times
        {
            ///// Check if the current queued-value matched conditions or not /////
            if (record_pq.top() > k) { break; }

            k -= record_pq.top(); record_pq.pop(); //Keep updating, popped

        } //K-th times

        return record_pq.size();
    }
};
