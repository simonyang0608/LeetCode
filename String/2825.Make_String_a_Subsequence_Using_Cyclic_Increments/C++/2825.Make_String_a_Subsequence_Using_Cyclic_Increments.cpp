class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        //==========================//
        // Input type:              //
        //   - string (str1 string) //
        //   - string (str2 string) //
        // Return type:             //
        //   - bool (result flag)   //
        //==========================//

        /*Initialize*/
        ///// Length of strings (i.e. str1, str2) /////
        int len_str1 = str1.size(), len_str2 = str2.size();

        ///// Record pointers (i.e. str1, str2)
        int record_str1_ptr = 0, record_str2_ptr = 0;


        /*Two-pointers based loop traversal*/
        while ((record_str1_ptr < len_str1) && (record_str2_ptr < len_str2)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (((str1[record_str1_ptr] -'a') == (str2[record_str2_ptr] - 'a')) || ((((str1[record_str1_ptr] -'a') + 1) % 26) == (str2[record_str2_ptr] - 'a')))
            {
                (record_str2_ptr++); //Keep updating, traversing
            }
            else { ; }

            (record_str1_ptr++); //Keep updating, traversing

        } //Whole

        return (record_str2_ptr >= len_str2) ? true : false;
    }
};
