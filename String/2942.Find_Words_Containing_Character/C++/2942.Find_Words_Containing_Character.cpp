class Solution {
public:
    vector<int> findWordsContaining(vector<string> & words, char x) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<string> ref. (words vector) //
        //   - char (x char)                      //
        // Return type:                           //
        //   - vector<int> (result vector)        //
        //========================================//

        /*Initialize*/
        ///// Length of words vector /////
        int len_words = words.size();

        ///// Result vector /////
        vector<int> res_vect;


        /*One-pass record based loop traversal*/
        for (int words_idx = 0; (words_idx < len_words); (words_idx++)) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if ((words[words_idx]).find(x) == string::npos) { continue; }

            res_vect.emplace_back(words_idx); //Keep updating, recording

        } //Whole

        return res_vect;
    }
};
