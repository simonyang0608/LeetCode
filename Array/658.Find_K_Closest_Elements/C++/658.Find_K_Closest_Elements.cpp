class Solution {
public:
    vector<int> findClosestElements(vector<int> & arr, int k, int x) 
    {
        //===================================//
        // Input type:                       //
        //   - vector<int> ref. (arr vector) //
        //   - int (k-th elements)           //
        //   - int (x target value)          //
        // Return type:                      //
        //   - vector<int> (result vector)   //
        //===================================//
        if (x <= arr.front()) //Issue, Boundary-case handling
        {
            vector<int> sub_vect((arr.begin() + 0), (arr.begin() + k)); //Sub-vector from 0 to k-indexed

            return sub_vect; 
        }

        else if (x >= arr.back()) //Issue, Boundary-case handling
        {
            vector<int> sub_vect((arr.begin() + (arr.size() - k)), (arr.begin() + arr.size())); //Sub-vector from the last k-th elements/values

            return sub_vect;
        }


        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 1;

        ///// Record differences (i.e. left, right) /////
        int record_left_diff, record_right_diff;

        ///// Result vector /////
        vector<int> res_vect;


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for the index/place of x target value /////
        while (record_left_ptr < len_arr) //Part
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (arr[(record_left_ptr + 1)] > x)
            {
                record_right_ptr += record_left_ptr; //Update, Accumulate

                break;
            }

            (record_left_ptr++); //Keep updating, accumulating

        } //Part

        ///// Step 2: Post-process, Final completions /////
        for (int k_idx = 0; (k_idx < k); (k_idx++)) //K-th times
        {
            ///// Check if the current pointer exceed boundary or not /////
            if (record_left_ptr >= 0)
            {
                if (record_right_ptr < len_arr)
                {
                    record_left_diff = (x - arr[record_left_ptr]); //Record left-half difference
                    record_right_diff = (arr[record_right_ptr] - x); //Record right-half difference

                    ///// Check if the current difference matched conditions or not /////
                    if (record_left_diff <= record_right_diff) 
                    { 
                        res_vect.insert((res_vect.begin() + 0), arr[record_left_ptr]); //Keep updating, recording

                        (record_left_ptr--); //Keep updating, reducing
                    }

                    else
                    {
                        res_vect.emplace_back(arr[record_right_ptr]); //Keep updating, recording

                        (record_right_ptr++); //Keep updating, accumulating
                    }
                }

                else
                {
                    res_vect.insert((res_vect.begin() + 0), arr[record_left_ptr]); //Keep updating, recording

                    (record_left_ptr--); //Keep updating, reducing
                }
            }

            else
            {
                if (record_right_ptr < len_arr)
                {
                    res_vect.emplace_back(arr[record_right_ptr]); //Keep updating, recording

                    (record_right_ptr++); //Keep updating, accumulating
                }

                else { ; }
            }

        } //K-th times

        return res_vect;
    }
};
