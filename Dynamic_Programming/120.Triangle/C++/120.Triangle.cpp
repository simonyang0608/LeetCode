class Solution {
public:
    int minimumTotal(vector<vector<int>> & triangle) 
    {
        //================================================//
        // Input type:                                    //
        //   - vector<vector<int>> ref. (triangle vector) //
        // Return type:                                   //
        //   - int (result minimun summary value)         //
        //================================================//

        /*Initialize*/
        ///// Length of triangle vector /////
        int len_triangle = triangle.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((triangle.back()).begin(), (triangle.back()).end());


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int triangle_idx = (len_triangle - 2); (triangle_idx >= 0); (triangle_idx--)) //Whole
        {
            for (int record_idx = 0; (record_idx <= triangle_idx); (record_idx++)) //Part
            {
                record_dp[record_idx] = (min(record_dp[record_idx], record_dp[(record_idx + 1)]) + 
                                        (triangle[triangle_idx])[record_idx]); //Keep updating, overwriting

            } //Part

        } //Whole

        return record_dp[0];
    }
};
