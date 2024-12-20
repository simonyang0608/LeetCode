class Solution {
public:
    vector<int> twoSum(vector<int> & numbers, int target) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (numbers vector) //
        //   - int (target value)                //
        // Return type:                          //
        //   - vector<int> (result vector)       //
        //=======================================//

        /*Initialize*/
        ///// Lengt of numbers vector /////
        int len_numbers = numbers.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_numbers - 1);


        /*Two-pointers based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Two-pointers search
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((numbers[record_left_ptr] + numbers[record_right_ptr]) < target) { (record_left_ptr++); } //Keep updating, traversing

            else if ((numbers[record_left_ptr] + numbers[record_right_ptr]) > target) { (record_right_ptr--); } //Keep updating, traversing
            else { return {(record_left_ptr + 1), (record_right_ptr + 1)}; }

        } //Two-pointers search

        return {(-1), (-1)};
    }
};
