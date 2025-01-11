class Solution {
public:
    int findMinArrowShots(vector<vector<int>> & points) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (points vector) //
        // Return type:                                 //
        //   - int (result summary counter)             //
        //==============================================//

        /*Initialize*/
        ///// Length of points vector /////
        int len_points = points.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Greedy-based loop traversal*/
        sort(points.begin(), points.end(), [](const vector<int> & val1, const vector<int> & val2) //Sorted operations
        {
            return (val1[1] < val2[1]);
        });

        while (record_trav_ptr < len_points) //Whole
        {
            int end_val = (points[record_trav_ptr])[1]; //End-value

            (res_cnter++); //Keep updating, accumulating

            while (((record_trav_ptr + 1) < len_points) && ((points[(record_trav_ptr + 1)])[0] <= end_val)) //Part
            {
                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_cnter;
    }
};
