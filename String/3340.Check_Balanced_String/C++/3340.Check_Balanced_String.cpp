class Solution {
public:
    bool isBalanced(string num) 
    {
        //=========================//
        // Input type:             //
        //   - string (num string) //
        // Return type:            //
        //   - bool (result flag)  //
        //=========================//

        /*Initialize*/
        ///// Length of nums string /////
        int len_num = num.size();

        ///// Record two-pointers (i.e. even, odd) /////
        int record_even_ptr = 0, record_odd_ptr = 1;

        ///// Result summary values (i.e. even, odd) /////
        int res_sum_even = 0, res_sum_odd = 0;


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for the overlap-part /////
        while ((record_even_ptr < len_num) && (record_odd_ptr < len_num)) //Overlap-part
        {
            res_sum_even += (num[record_even_ptr] - '0'); //Keep updating, accumulating
            res_sum_odd += (num[record_odd_ptr] - '0'); //Keep updating, accumulating

            record_even_ptr += 2; //Keep updating, traversing
            record_odd_ptr += 2; //Keep updating, traversing

        } //Overlap-part

        ///// Step 2: Looped-traversal for the remainings /////
        while (record_even_ptr < len_num) //Remainings
        {
            res_sum_even += (num[record_even_ptr] - '0'); //Keep updating, accumulating

            record_even_ptr += 2; //Keep updating, traversing

        } //Remainings

        while (record_odd_ptr < len_num) //Remainings
        {
            res_sum_odd += (num[record_odd_ptr] - '0'); //Keep updating, accumulating

            record_odd_ptr += 2; //Keep updating, traversing

        } //Remainings

        return (res_sum_even == res_sum_odd) ? true : false;
    }
};
