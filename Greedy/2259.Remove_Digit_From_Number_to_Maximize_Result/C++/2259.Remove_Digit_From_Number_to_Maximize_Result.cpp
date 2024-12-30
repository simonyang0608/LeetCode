class Solution {
public:
    string removeDigit(string number, char digit) 
    {
        //============================//
        // Input type:                //
        //   - string (number string) //
        //   - char (digit)           //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of number string /////
        int len_number = number.size();

        ///// Record vector /////
        vector<string> record_vect;


        /*Greedy-based loop traversal*/
        for (int number_idx = 0; (number_idx < len_number); (number_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (number[number_idx] == digit)
            {
                string record_str = (number.substr(0, number_idx) + number.substr((number_idx + 1), (len_number - number_idx - 1))); //Record string

                record_vect.push_back(record_str); //Keep updating, recording
            }
            else { ; }

        } //Whole

        sort(record_vect.begin(), record_vect.end()); //Sorted operations

        return record_vect.back();
    }
};
