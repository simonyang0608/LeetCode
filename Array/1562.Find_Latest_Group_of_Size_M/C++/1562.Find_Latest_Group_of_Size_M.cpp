class Solution {
public:
    int findLatestStep(vector<int> & arr, int m) 
    {
        //===================================//
        // Input type:                       //
        //   - vector<int> ref. (arr vector) //
        //   - int (m-th length)             //
        // Return type:                      //
        //   - int (result maximun steps)    //
        //===================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record vectors (i.e. length, counter) /////
        vector<int> length_vect((len_arr + 2), 0), cnter_vect((len_arr + 1), 0);

        ///// Result steps /////
        int res_steps = (-1);


        /*Prefix-summary based loop traversal with recorded vectors*/
        for (int arr_idx = 0; (arr_idx < len_arr); (arr_idx++)) //Whole
        {
            int left = length_vect[(arr[arr_idx] - 1)]; int right = length_vect[(arr[arr_idx] + 1)]; //Left, Right

            int record_sum_val = (left + right + 1); //Record summary value

            length_vect[(arr[arr_idx] - left)] = record_sum_val; //Keep updating, overwriting
            length_vect[(arr[arr_idx] + right)] = record_sum_val; //Keep updating, overwriting

            ((cnter_vect[left])--); ((cnter_vect[right])--); //Keep updating, reducing

            ((cnter_vect[record_sum_val])++); //Keep updating, accumulating

            ///// Check if the current summary counter matched conditions or not /////
            if (cnter_vect[m] > 0) { res_steps = (arr_idx + 1); } //Keep updating, overwriting
            else { ; }

        } //Whole

        return res_steps;
    }
};
