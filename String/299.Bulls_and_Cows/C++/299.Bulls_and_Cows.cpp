class Solution {
public:
    string getHint(string secret, string guess) 
    {
        //============================//
        // Input type:                //
        //   - string (secret string) //
        //   - string (guess string)  //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of secret string /////
        int len_secret = secret.size();

        ///// Record dictionary, hashmap /////
        unordered_map<char, int> record_map;

        ///// Result summary counters (i.e. a, b) /////
        int res_cnter_a = 0, res_cnter_b = 0;


        /*Hashmap-based loop traversal with recorded summary counters*/
        ///// Step 1: Record indexed-char information with dictionary, hashmap /////
        for (int secret_idx = 0; (secret_idx < len_secret); (secret_idx++)) //Whole
        {
            ((record_map[secret[secret_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the recorded dictionary, hashmap /////
        for (int guess_idx = 0; (guess_idx < len_secret); (guess_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (secret[guess_idx] == guess[guess_idx])
            {
                ((record_map[guess[guess_idx]])--); //Keep updating, reducing

                (res_cnter_a++); //Keep updating, accumulating
            }
            else { ; }

        } //Whole

        for (int guess_idx = 0; (guess_idx < len_secret); (guess_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (secret[guess_idx] == guess[guess_idx]) { continue; }

            ///// Check if the current summary counter matched conditions or not /////
            if ((--(record_map[guess[guess_idx]])) >= 0) { (res_cnter_b++); } //Keep updating, accumulating
            else { ; }

        } //Whole

        return (to_string(res_cnter_a) + 'A' + to_string(res_cnter_b) + 'B');
    }
};
