class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        //============================//
        // Input type:                //
        //   - string (word1 string)  //
        //   - string (word2 string)  //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of strings (i.e. word1, word2) /////
        int len_word1 = word1.size(), len_word2 = word2.size();

        ///// Record pointers (i.e. word1, word2) /////
        int record_ptr_word1 = 0, record_ptr_word2 = 0;

        ///// Result string /////
        string res_str;


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for the fixed-intervals /////
        while ((record_ptr_word1 < len_word1) && (record_ptr_word2 < len_word2)) //Intervals
        {
            res_str += word1[(record_ptr_word1++)]; //Keep updating, recording

            res_str += + word2[(record_ptr_word2++)]; //Keep updating, recording

        } //Intervals

        ///// Step 2: Looped-traversal for the remainings /////
        while (record_ptr_word1 < len_word1) { res_str += word1[(record_ptr_word1++)]; } //Keep updating, recording

        while (record_ptr_word2 < len_word2) { res_str += word2[(record_ptr_word2++)]; } //Keep updating, recording

        return res_str;
    }
};
