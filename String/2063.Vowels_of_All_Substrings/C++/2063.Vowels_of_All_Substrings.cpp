class Solution {
public:
    long long countVowels(string word) 
    {
        //======================================//
        // Input type:                          //
        //   - string (word string)             //
        // Return type:                         //
        //   - long long (result summary value) //
        //======================================//

        /*Initialize*/
        ///// Length of word vector /////
        int len_word = word.size();

        ///// Record dictionary, hashmap /////
        map<char, bool> record_map;

        ///// Result summary value /////
        long long res_sum_val = 0;


        /*One-pass update based loop traversal with recorded dictionary, hashmap*/
        record_map['a'] = true; record_map['e'] = true; record_map['i'] = true; 
        record_map['o'] = true; record_map['u'] = true; //Update, Record

        for (int word_idx = 0; (word_idx < len_word); (word_idx++)) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if (record_map.find(word[word_idx]) != record_map.end())
            {
                res_sum_val += (((long long)(word_idx) + 1) * (len_word - (long long)(word_idx))); //Keep updating, accumulating
            }
            else { ; }

        } //Whole

        return res_sum_val;
    }
};
