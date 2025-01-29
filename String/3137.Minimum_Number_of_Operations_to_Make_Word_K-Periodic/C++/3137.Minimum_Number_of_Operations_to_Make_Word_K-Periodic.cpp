class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) 
    {
        //=====================================//
        // Input type:                         //
        //   - string (word string)            //
        //   - int (k-th order)                //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of word string /////
        int len_word = word.size();

        ///// Total summary counter /////
        int total_cnter = (len_word / k);

        ///// Record dictionary, hashmap /////
        unordered_map<string, int> record_map;

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_trav_ptr < len_word) //Whole
        {
            string record_str = word.substr(record_trav_ptr, k); //Record string

            ((record_map[record_str])++); //Keep updating, recording

            res_max_cnter = max(res_max_cnter, (record_map[record_str])); //Keep updating, overwriting

            record_trav_ptr += k; //Keep updating, traversing

        } //Whole

        return (total_cnter - res_max_cnter);
    }
};
