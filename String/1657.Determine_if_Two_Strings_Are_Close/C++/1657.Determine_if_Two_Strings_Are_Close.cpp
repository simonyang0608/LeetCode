class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        //===========================//
        // Input type:               //
        //   - string (word1 string) //
        //   - string (word2 string) //
        // Return type:              //
        //   - bool (result flag)    //
        //===========================//

        /*Initialize*/
        ///// Length of strings (i.e. word1, word2) /////
        int len_word1 = word1.size(), len_word2 = word2.size();

        if (len_word1 != len_word2) { return false; } //Issue, Boundary-case handling

        ///// Record vectors (i.e. word1, word2) /////
        vector<int> record_vect_word1(26, 0), record_vect_word2(26, 0);


        /*String counting-based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-char informations with vectors /////
        for (int word1_idx = 0; (word1_idx < len_word1); (word1_idx++)) //Word1
        {
            ((record_vect_word1[(word1[word1_idx] - 'a')])++); //Keep updating, accumulating

        } //Word1

        for (int word2_idx = 0; (word2_idx < len_word2); (word2_idx++)) //Word2
        {
            ///// Check if the current indexed-char existed in word1 or not /////
            if (! record_vect_word1[(word2[word2_idx] - 'a')]) { return false; }

            ((record_vect_word2[(word2[word2_idx] - 'a')])++); //Keep updating, accumulating

        } //Word2

        ///// Step 2: Looped-traversal with recorded vector /////
        sort(record_vect_word1.begin(), record_vect_word1.end()); //Sorted operations
        sort(record_vect_word2.begin(), record_vect_word2.end()); //Sorted operations

        for (int record_idx = 0; (record_idx < 26); (record_idx++)) //Whole
        {
            ///// Check if the summary counter matched conditions or not /////
            if (record_vect_word1[record_idx] != record_vect_word2[record_idx]) { return false; }

        } //Whole

        return true;
    }
};
