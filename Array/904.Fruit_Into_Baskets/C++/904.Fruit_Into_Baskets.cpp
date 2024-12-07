class Solution {
public:
    int totalFruit(vector<int> & fruits) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (fruits vector)     //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of fruits vector /////
        int len_fruits = fruits.size();

        if (len_fruits < 3) { return len_fruits; } //Issue, Boundary-case handling

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_fruits) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(fruits[record_right_ptr]) == record_map.end())
            {
                record_map[fruits[record_right_ptr]] = 1; //Keep updating, recording
            }
            else { record_map[fruits[record_right_ptr]] += 1; } //Keep updating, recording

            while (record_map.size() > 2) //Part
            {
                record_map[fruits[record_left_ptr]] -= 1; //Keep updating, recording

                ///// Check if the current indexed-value matched conditions or not ///// 
                if (! record_map[fruits[record_left_ptr]])
                {
                    record_map.erase(fruits[record_left_ptr]); //Keep updating, delete
                }
                else { ; }

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            res_max_cnter = max(res_max_cnter, ((record_right_ptr - record_left_ptr) + 1)); //Keep updating, overwriting

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_cnter;
    }
};
