class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> & candidates, int target) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (candidates vector) //
        //   - int (target value)                   //
        // Return type:                             //
        //   - vector<vector<int>> (result vector)  //
        //==========================================//

        /*Initialize*/
        ///// Length of candidates vector /////
        int len_candidates = candidates.size();

        ///// Record summary value /////
        int record_sum_val = 0;

        ///// Record vector /////
        vector<int> record_vect;

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Recursion-based backtracking-based loop traversal*/
        sort(candidates.begin(), candidates.end()); //Sorted operations

        backtrackTraversal(len_candidates, candidates, target, 0, res_vect, record_vect); //Recursion function call

        return res_vect;
    }


    void backtrackTraversal(const int & len_candidates, const vector<int> & candidates, int target, int record_idx,
                            vector<vector<int>> & res_vect, vector<int> & record_vect)
    {
        //==================================================//
        // Input type:                                      //
        //   - const int ref. (length of candidates vector) //
        //   - const vector<int> ref. (candidates vector)   //
        //   - int (target value)                           //
        //   - int (record index)                           //
        //   - vector<vector<int>> ref. (result vector)     //
        //   - vector<int> ref. (record vector)             //
        // Return type:                                     //
        //   - void (no return)                             //
        //==================================================//
        if (record_idx >= len_candidates) { return; } //Issue, Boundary-case handling

        if (target < 0) { return; } //Issue, Boundary-case handling

        if (! target) { res_vect.push_back(record_vect); return; } //Issue, Boundary-case handling


        /*Whole process, flow*/
        for (int sub_idx = record_idx; (sub_idx < len_candidates); (sub_idx++)) //Whole
        {
            record_vect.emplace_back(candidates[sub_idx]); //Keep updating, recording

            backtrackTraversal(len_candidates, candidates, (target - candidates[sub_idx]), sub_idx, res_vect, record_vect); //Recursion function call

            record_vect.pop_back(); //Keep updating, popped

        } //Whole
    }
};
