class Solution {
public:
    string shiftingLetters(string s, vector<int> & shifts) 
    {
        //======================================//
        // Input type:                          //
        //   - string (s string)                //
        //   - vector<int> ref. (shifts vector) //
        // Return type:                         //
        //   - string (result string)           //
        //======================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record shifts vector /////
        vector<long long> record_shifts(len_s, 0);

        ///// Result string /////
        string res_str = "";


        /*Prefix-summary based loop traversal*/
        ///// Step 1: Record prefix-summary informations with vector /////
        for (int record_idx = (len_s - 1); (record_idx >= 0); (record_idx--)) //Whole
        {
            record_shifts[record_idx] += (shifts[record_idx]); //Keep updating, recording

            ///// Check if the current index matched conditions or not /////
            if ((record_idx + 1) >= len_s) { ; }
            else { record_shifts[record_idx] += record_shifts[(record_idx + 1)]; } //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded prefix-summary vector /////
        for (int record_idx = 0; (record_idx < len_s); (record_idx++)) //Whole
        {
            int res_shifted = (((s[record_idx] - 'a') + record_shifts[record_idx]) % 26); //Result shifted-value

            res_str += (char)('a' + res_shifted); //Keep updating, recording

        } //Whole

        return res_str;
    }
};
