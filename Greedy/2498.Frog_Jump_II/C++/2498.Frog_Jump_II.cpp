class Solution {
public:
    int maxJump(vector<int> & stones) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (stones vector) //
        // Return type:                         //
        //   - int (result maximun distance)    //
        //======================================//

        /*Initialize*/
        ///// Length of stones vector /////
        int len_stones = stones.size();

        ///// Record pointers /////
        int record_trav_ptr1 = 0, record_trav_ptr2 = 1;

        ///// Result maximun distance /////
        int res_max_dist = (stones[1] - stones.front());


        /*Greedy-based loop traversal*/
        ///// Step 1: Looped-traversal for the first jump /////
        while ((record_trav_ptr1 + 2) < len_stones) //First-jump
        {
            res_max_dist = max(res_max_dist, (stones[(record_trav_ptr1 + 2)] - stones[record_trav_ptr1])); //Keep updating, overwriting

            record_trav_ptr1 += 2; //Keep updating, traversing

        } //First-jump

        if (record_trav_ptr1 < (len_stones - 1)) { res_max_dist = max(res_max_dist, stones.back() - stones[record_trav_ptr1]); } //Update, Overwrite
        else { ; }

        ///// Step 2: Looped-traversal for the second jump /////
        while ((record_trav_ptr2 + 2) < len_stones) //Second-jump
        {
            res_max_dist = max(res_max_dist, (stones[(record_trav_ptr2 + 2)] - stones[record_trav_ptr2])); //Keep updating, overwriting

            record_trav_ptr2 += 2; //Keep updating, traversing

        } //Second-jump

        if (record_trav_ptr2 < (len_stones - 1)) { res_max_dist = max(res_max_dist, stones.back() - stones[record_trav_ptr2]); } //Update, Overwrite
        else { ; }

        return res_max_dist;
    }
};
