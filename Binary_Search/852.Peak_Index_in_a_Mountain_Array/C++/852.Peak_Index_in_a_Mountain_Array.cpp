class Solution {
public:
    int peakIndexInMountainArray(vector<int> & arr) 
    {
        //===================================//
        // Input type:                       //
        //   - vector<int> ref. (arr vector) //
        // Return type:                      //
        //   - int (result index)            //
        //===================================//

        /*Initialize*/
        ///// Length of arr vector /////
        arr.insert(arr.begin(), 0);
        arr.emplace_back(0);

        int len_arr = arr.size();

        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 1, record_right_ptr = (len_arr - 1);

        ///// Result index, maximun value /////
        int res_idx, res_max_val = (-1);


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Whole
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            ///// Check if the current indexed-value matched conditions or not /////
            if (arr[record_mid_ptr] >= arr[(record_mid_ptr - 1)])
            {
                if (arr[record_mid_ptr] > res_max_val)
                {
                    res_max_val = arr[record_mid_ptr]; //Keep updating, overwriting

                    res_idx = record_mid_ptr; //Keep updating, overwriting
                }
                else { ; }

                record_left_ptr = (record_mid_ptr + 1); //Keep updating, overwriting
            }

            else
            {
                if (arr[(record_mid_ptr - 1)] > res_max_val)
                {
                    res_max_val = arr[(record_mid_ptr - 1)]; //Keep updating, overwriting

                    res_idx = (record_mid_ptr - 1); //Keep updating, overwriting
                }
                else { ; }

                record_right_ptr = (record_mid_ptr - 1); //Keep updating, overwriting
            }

        } //Whole

        return (res_idx - 1);
    }
};
