class Solution {
public:
    void recurseTraversal(int record_val_pair_idx, vector<int> & cost, int & res_min_oprs)
    {
        //==========================================//
        // Input type:                              //
        //   - int (record node value pairs index)  //
        //   - vector<int> ref. (cost vector)       //
        //   - int ref. (result minimun operations) //
        // Return type:                             //
        //   - void (no return)                     //
        //==========================================//
        if ((record_val_pair_idx < 0)) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        res_min_oprs += abs(cost[((record_val_pair_idx << 1) + 1)] - cost[((record_val_pair_idx << 1) + 2)]); //Update, Accumulate
        cost[record_val_pair_idx] += max(cost[((record_val_pair_idx << 1) + 1)], cost[((record_val_pair_idx << 1) + 2)]); //Update, Accumulate

        recurseTraversal((record_val_pair_idx - 1), cost, res_min_oprs); //Recursion function call
    }


    int minIncrements(int n, vector<int> & cost) 
    {
        //=====================================//
        // Input type:                         //
        //   - int (n-th tree nodes)           //
        //   - vector<int> ref. (cost vector)  //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Result minimun operations /////
        int res_min_oprs = 0;

        /*Recursion-based loop traversal*/
        recurseTraversal(((n / 2) - 1), cost, res_min_oprs); //Recursion function call

        return res_min_oprs;
    }
};
