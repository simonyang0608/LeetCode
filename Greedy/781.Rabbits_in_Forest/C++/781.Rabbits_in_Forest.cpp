class Solution {
public:
    int numRabbits(vector<int> & answers) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (answers vector)    //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of answers vector /////
        int len_answers = answers.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Result summary counter /////
        int res_cnter = 0;

        
        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int answers_idx = 0; (answers_idx < len_answers); (answers_idx++)) //Whole
        {
            ((record_map[answers[answers_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (auto record_ele = record_map.begin(); (record_ele != record_map.end()); (record_ele++)) //Whole
        {
            int record_ref = (record_ele->first); int record_cnter = (record_ele->second); //Record reference, summary counter

            int record_quot = (record_cnter / (record_ref + 1)); int record_module = (record_cnter % (record_ref + 1)); //Record quotient, module

            ///// Check if the current module matched conditions or not /////
            if (record_module) { res_cnter += ((record_ref + 1) * (record_quot + 1)); } //Keep updating, accumulating
            else { res_cnter += ((record_ref + 1) * record_quot); } //Keep updating, accumulating

        } //Whole

        return res_cnter;
    }
};
