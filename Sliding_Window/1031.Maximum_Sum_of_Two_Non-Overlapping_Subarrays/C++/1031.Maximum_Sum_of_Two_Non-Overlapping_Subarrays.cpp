class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> & nums, int firstLen, int secondLen) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums vector)     //
        //   - int (length of first sub-array)    //
        //   - int (length of second sub-array)   //
        // Return type:                           //
        //   - int (result maximun summary value) //
        //========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        /*Sliding-window based loop traversal*/
        int res_max_sum1 = sldWindow(len_nums, nums, firstLen, secondLen); //Result maximun summary value (i.e. 1)
        int res_max_sum2 = sldWindow(len_nums, nums, secondLen, firstLen); //Result maximun summary value (i.e. 2)

        return (res_max_sum1 > res_max_sum2) ? res_max_sum1 : res_max_sum2;
    }


    int sldWindow(const int & len_nums, const vector<int> & nums, const int & first_info, 
                  const int & second_info)
    {
        //============================================//
        // Input type:                                //
        //   - const int ref. (length of nums vector) //
        //   - const vector<int> ref. (nums vector)   //
        //   - const int ref. (first length info.)    //
        //   - const int ref. (second length info.)   //
        // Return type:                               //
        //   - int (result maximun summary value)     //
        //============================================//

        /*Initialize*/
        ///// Total informations /////
        int total_info = (first_info + second_info);

        ///// Record summary values (i.e. first, second) /////
        int record_sum_first = 0, record_sum_second = 0;

        ///// Result maximun values (i.e. first, total) /////
        int res_max_first = (-1), res_max_total = (-1);


        /*Whole process, flow*/
        ///// Step 1: Looped-traversal for the fixed-window size /////
        for (int record_idx = 0; (record_idx < total_info); (record_idx++)) //Fixed-window
        {
            ///// Check if the current index belongs to which boundaries /////
            if (record_idx < first_info) { record_sum_first += nums[record_idx]; } //Keep updating, accumulating
            else { record_sum_second += nums[record_idx]; } //Keep updating, accumulating
             
        } //Fixed-window

        ///// Step 2: Looped-traversal for the remainings /////
        res_max_first = record_sum_first; res_max_total = (res_max_first + record_sum_second); //Update, Overwrite

        for (int record_idx = total_info; (record_idx < len_nums); (record_idx++)) //Remainings
        {
            record_sum_first += (nums[(record_idx - second_info)] - nums[(record_idx - second_info - first_info)]); //Keep updating, accumulating

            res_max_first = (record_sum_first > res_max_first) ? record_sum_first : res_max_first; //Keep updating, overwriting

            record_sum_second += (nums[record_idx] - nums[(record_idx - second_info)]); //Keep updating, accumulating

            res_max_total = ((res_max_first + record_sum_second) > res_max_total) ? 
                             (res_max_first + record_sum_second) : res_max_total; //Keep updating, overwriting

        } //Remainings

        return res_max_total;
    }
};
