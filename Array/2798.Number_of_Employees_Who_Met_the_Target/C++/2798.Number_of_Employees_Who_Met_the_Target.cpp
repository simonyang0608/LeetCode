class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int> & hours, int target) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (hours vector) //
        //   - int (target value)              //
        // Return type:                        //
        //   - int (result summary counter)    //
        //=====================================//

        /*Initialize*/
        ///// Length of hours vector /////
        int len_hours = hours.size();

        ///// Result summary counter /////
        int res_cnter = 0;


        /*One-pass compare based loop traversal*/
        for (int hours_idx = 0; (hours_idx < len_hours); (hours_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not //////
            if (hours[hours_idx] >= target) { (res_cnter++); } //Keep updating, accumulating
            else { ; }
             
        } //Whole

        return res_cnter;
    }
};
