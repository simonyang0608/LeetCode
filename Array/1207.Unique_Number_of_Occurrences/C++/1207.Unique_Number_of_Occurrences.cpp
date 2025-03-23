class Solution {
public:
    bool uniqueOccurrences(vector<int> & arr) 
    {
        //===================================//
        // Input type:                       //
        //   - vector<int> ref. (arr vector) //
        // Return type:                      //
        //   - bool (result flag)            //
        //===================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map_val, record_map_cnter;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record summary counter with dictionary, hashmap /////
        for (int arr_idx = 0; (arr_idx < len_arr); (arr_idx++)) //Whole
        {
            ((record_map_val[arr[arr_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the recorded dictionary, hashmap /////
        for (auto record_ele = record_map_val.begin(); (record_ele != record_map_val.end()); (record_ele++)) //Whole
        {
            ((record_map_cnter[(record_ele->second)])++); //Keep updating, recording

            ///// Check if the current summary counter unique or not /////
            if (record_map_cnter[record_ele->second] > 1) { return false; }

        } //Whole

        return true;
    }
};
