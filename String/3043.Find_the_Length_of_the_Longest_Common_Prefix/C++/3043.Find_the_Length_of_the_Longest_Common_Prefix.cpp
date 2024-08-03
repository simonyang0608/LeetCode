class Solution {
public:
    int longestCommonPrefix(vector<int> & arr1, vector<int> & arr2) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (arr1 vector)       //
        //   - vector<int> ref. (arr2 vector)       //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of arrs vector (i.e. arr1, arr2) /////
        int len_arr1 = arr1.size(), len_arr2 = arr2.size();

        ///// Record hashmap, dictionaries (i.e. arr1, arr2) /////
        unordered_map<string, bool> record_map_arr1, record_map_arr2;

        ///// Record, Current indexed-string /////
        string record_str, curr_str;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Greedy-based loop traversal with recorded hashmap, dictionary*/
        ///// Step 1: Record indexed-string with hashmap, dictionary /////
        for (int arr1_idx = 0; (arr1_idx < len_arr1); (arr1_idx++)) //Whole
        {
            curr_str = to_string(arr1[arr1_idx]); //Current indexed-string

            for (char curr_char: curr_str) //Whole
            {
                record_str += curr_char; //Keep updating, recording

                ///// Check if the current indexed-string existed or not /////
                if (record_map_arr1.find(record_str) == record_map_arr1.end())
                {
                    record_map_arr1[record_str] = true; //Keep updating, recording
                }
                else { ; }

            } //Whole

            record_str.clear(); //Reset

        } //Whole

        ///// Step 2: Looped-traversal with recorded hashmap /////
        for (int arr2_idx = 0; (arr2_idx < len_arr2); (arr2_idx++)) //Whole
        {
            curr_str = to_string(arr2[arr2_idx]); //Current indexed-string

            for (char curr_char: curr_str) //Whole
            {
                record_str += curr_char; //Keep updating, recording

                ///// Check if the current indexed-string existed or not /////
                if (record_map_arr1.find(record_str) != record_map_arr1.end())
                {
                    ///// Check if the current indexed-string existed or not /////
                    if (record_map_arr2.find(record_str) ==  record_map_arr2.end())
                    {
                        record_map_arr2[record_str] = true; //Keep updating, recording

                        res_max_cnter = (record_str.size() > res_max_cnter) ? record_str.size() : res_max_cnter; //Keep updating, overwriting
                    }
                    else { ; }
                }

                else { ; }

            } //Whole

            record_str.clear(); //Reset

        } //Whole

        return res_max_cnter;
    }
};
