class Solution {
public:
    int destroyTargets(vector<int> & nums, int space) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (space value)              //
        // Return type:                       //
        //   - int (result minimun value)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record visit dictionary, hashmap /////
        map<int, bool> visit_map;

        ///// Result value, maximun summary counter /////
        int res_val, res_max_cnter = 0;


        /*Hashmap-based loop traversal with sorted operations*/
        ///// Step 1: Record indexed-value informations with dictionary, hashmap /////
        sort(nums.begin(), nums.end()); //Sorted operations

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ((record_map[(nums[nums_idx] % space)])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int nums_idx = 0 ;(nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value is visited or not /////
            if (visit_map[(nums[nums_idx] % space)]) { continue; }

            int record_remains = (nums[nums_idx] % space); //Record remainings

            visit_map[record_remains] = true; //Keep updating, recording

            ///// Check if the current summary counter is larger or not /////
            if (record_map[record_remains] > res_max_cnter)
            {
                res_max_cnter = record_map[record_remains]; //Keep updating, overwriting

                res_val = nums[nums_idx]; //Keep updating, overwriting
            }
            else { ; }
        }

        return res_val;
    }
};
