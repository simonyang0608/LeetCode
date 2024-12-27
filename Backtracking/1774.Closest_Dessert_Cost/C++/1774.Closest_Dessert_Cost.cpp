class Solution {
public:
    int closestCost(vector<int> & baseCosts, vector<int> & toppingCosts, int target) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<int> ref. (baseCosts vector)    //
        //   - vector<int> ref. (toppingCosts vector) //
        //   - int (target value)                     //
        // Return type:                               //
        //   - int (result costs)                     //
        //============================================//

        /*Initialize*/
        ///// Length of vectors (i.e. baseCosts, toppingCosts) /////
        int len_baseCosts = baseCosts.size(), len_toppingCosts = toppingCosts.size();

        ///// Record minimun differences, costs /////
        int record_min_diff = 1e6, res_cost = 0;

        ///// Result dictionary, hashmap /////
        unordered_map<int, vector<int>> res_map;

        ///// Result minimun differences /////
        int res_min_diff = 1e6;


        /*Recursion-based backtracking loop traversal with recorded dictionary, hashmap*/
        for (int record_idx = 0; (record_idx < len_baseCosts); (record_idx++)) //Whole
        {
            recurseTraversal(toppingCosts, len_toppingCosts, 0, baseCosts[record_idx], target, res_cost, record_min_diff, res_map); //Recursion function call

            res_min_diff = min(res_min_diff, record_min_diff); //Keep updating, overwriting

            ///// Check if the current costs needs to be reset or not /////
            if (res_cost) { res_cost &= 0; } //Keep updating, reset
            else { ; }

            record_min_diff = 1e6; //Keep updating, overwriting

        } //Whole

        sort((res_map[res_min_diff]).begin(), (res_map[res_min_diff]).end()); //Sorted operations

        return (res_map[res_min_diff])[0];
    }


    void recurseTraversal(vector<int> & toppingCosts, int & len_toppingCosts, int record_idx, int record_cost, int & target, int & res_cost, int & record_min_diff, unordered_map<int, vector<int>> & res_map)
    {
        //=======================================================================//
        // Input type:                                                           //
        //   - vector<int> ref. (toppingCosts vector)                            //
        //   - int ref. (length of toppingCosts vector)                          //
        //   - int (record index)                                                //
        //   - int (record costs)                                                //
        //   - int (target value)                                                //
        //   - int ref. (result costs)                                           //
        //   - int ref. (record minimun differences)                             //
        //   - unordered_map<int, vector<int>> ref. (result dictionary, hashmap) //
        // Return type:                                                          //
        //   - void (no return)                                                  //
        //=======================================================================//
        if (record_idx >= len_toppingCosts) //Issue, Boundary-case handling
        {
            ///// Check if the current differences is smaller or not /////
            if (abs(target - record_cost) <= record_min_diff) { res_cost = record_cost; record_min_diff = abs(target - record_cost); (res_map[record_min_diff]).emplace_back(res_cost); } //Update, Overwrite

            return;
        }

        /*Whole process, flow*/
        recurseTraversal(toppingCosts, len_toppingCosts, (record_idx + 1), record_cost, target, res_cost, record_min_diff, res_map); //Recursion function call (i.e. no get)
        recurseTraversal(toppingCosts, len_toppingCosts, (record_idx + 1), (record_cost + toppingCosts[record_idx]), target, res_cost, record_min_diff, res_map); //Recursion function call (i.e. get once)
        recurseTraversal(toppingCosts, len_toppingCosts, (record_idx + 1), (record_cost + (toppingCosts[record_idx] * 2)), target, res_cost, record_min_diff, res_map); //Recursion function call (i.e. get twice)
    }
};
