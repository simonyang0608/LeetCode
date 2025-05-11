class Solution {
public:
    int alternatingSubarray(vector<int> & nums) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record char /////
        char record_chr = 'n';

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Sliding-window based loop traversal*/
        while (record_trav_ptr < len_nums) //Whole
        {
            ///// Check if the next indexed-pointer exceed boundary or not /////
            if ((record_trav_ptr + 1) < len_nums)
            {
                ///// Check if the current, next indexed-value matched conditions or not /////
                if (nums[record_trav_ptr] == (nums[(record_trav_ptr + 1)] + 1))
                {
                    ///// Check if the previous char matched conditions or not /////
                    if ((record_chr == 'n') || (record_chr == 'd'))
                    {
                        ///// Check if the current summary counter matched conditions or not /////
                        if (record_cnter) { record_cnter &= 0; } //Keep updating, reset
                        else { ; }

                        ///// Check if the current char matched conditions or not /////
                        if (record_chr == 'd') { record_chr = 'n'; } //Keep updating, overwriting
                        else { ; }
                    }
                    else { (record_cnter++); record_chr = 'd'; } //Keep updating, overwriting
                }

                else if ((nums[record_trav_ptr] + 1) == nums[(record_trav_ptr + 1)])
                {
                    ///// Check if the previous char matched conditions or not /////
                    if ((record_chr == 'n') || (record_chr == 'i'))
                    {
                        ///// Check if the current summary counter matched conditions or not /////
                        if (record_cnter != 2) { record_cnter = 2; } //Keep updating, overwriting
                        else { ; }

                        ///// Check if the current char matched conditions or not /////
                        if (record_chr == 'n') { record_chr = 'i'; } //Keep updating, overwriting
                        else { ; }
                    }
                    else { (record_cnter++); record_chr = 'i'; } //Keep updating, overwriting
                }
                else
                {
                    ///// Check if the current summary counter matched conditions or not /////
                    if (record_cnter)
                    {
                        record_cnter &= 0; //Keep updating, reset

                        record_chr = 'n'; //Keep updating, overwriting
                    }
                    else { ; }
                }
            }
            else { ; }

            res_max_cnter = (record_cnter > res_max_cnter) ? record_cnter : res_max_cnter; //Keep updating, overwriting

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return (! res_max_cnter) ? (-1) : res_max_cnter;
    }
};
