class Solution {
public:
    int chalkReplacer(vector<int> & chalk, int k) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (chalk vector) //
        //   - int (k-pieces chalk)            //
        // Return type:                        //
        //   - int (result index)              //
        //=====================================//

        /*Initialize*/
        ///// Length of chalk vector /////
        int len_chalk = chalk.size();

        ///// Summary of chalk vector /////
        long long sum_chalk = 0;

        for (int chalk_idx = 0; (chalk_idx < len_chalk); (chalk_idx++))
        {
            sum_chalk += chalk[chalk_idx];
        }

        ///// Result remainings /////
        long long res_remain = (k % sum_chalk);
        

        /*Greedy-based loop traversal*/
        for (int chalk_idx = 0; (chalk_idx < len_chalk); (chalk_idx++)) //Whole
        {   
            res_remain -= chalk[chalk_idx]; //Keep updating, reducing

            ///// Check if the current remainings matched conditions or not /////
            if (res_remain < 0) { return chalk_idx; }

        } //Whole

        return (-1);
    }
};
