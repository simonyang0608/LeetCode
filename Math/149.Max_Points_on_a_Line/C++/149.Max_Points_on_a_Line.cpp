class Solution {
public:
    int maxPoints(vector<vector<int>> & points) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (points vector) //
        // Return type:                                 //  
        //   - int (result maximun summary counter)     //
        //==============================================//

        /*Initialize*/
        ///// Length of points vector /////
        int len_points = points.size();

        ///// Record dictionary, hashmap /////
        map<double, int> record_map;

        ///// Result maximun summary counter /////
        int res_max_sum = 1;


        /*Hashmap-based loop trraversal*/
        sort(points.begin(), points.end(), [](const vector<int> & point1, const vector<int> & point2)
        {
            return (point1[1] < point2[1]);
        }); //Sorted operations

        for (int points_idx = 0; (points_idx < (len_points - 1)); (points_idx++)) //Major
        {
            for (int sub_points_idx = (points_idx + 1); (sub_points_idx < len_points); (sub_points_idx++)) //Sub
            {
                double record_relative = ((points[points_idx])[0] == (points[sub_points_idx])[0]) ? (1e8 + 1.00) : (static_cast<double>(((points[points_idx])[1] - (points[sub_points_idx])[1])) / static_cast<double>(((points[points_idx])[0] - (points[sub_points_idx])[0]))); //Record relative-value

                ((record_map[record_relative])++); //Keep updating, accumulating

                res_max_sum = max(res_max_sum, ((record_map[record_relative] + 1))); //Result maximun summary value

            } //Sub

            record_map.clear(); //Keep updating, reset

        } //Major

        return res_max_sum;
    }
};
