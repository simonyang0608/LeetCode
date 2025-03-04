class Solution {
public:
    int getLastMoment(int n, vector<int> & left, vector<int> & right) 
    {
        //=====================================//
        // Input type:                         //
        //   - int (n-th length)               //
        //   - vector<int> ref. (left vector)  //
        //   - vector<int> ref. (right vector) //
        // Return type:                        //
        //   - int (result summary counter)    //
        //=====================================//

        /*Initialize*/
        ///// Result summary counter /////
        int res_cnter = 0;

        /*Greedy-based loop traversal with sorted-operations*/
        ///// Check if the current vector is empty or not /////
        if (! left.empty()) { sort(left.begin(), left.end()); res_cnter = max(res_cnter, left.back()); } //Update, Overwrite
        else { ; }

        if (! right.empty()) { sort(right.begin(), right.end()); res_cnter = max(res_cnter, (n - right.front())); } //Update, Overwrite
        else { ; }

        return res_cnter;
    }
};
